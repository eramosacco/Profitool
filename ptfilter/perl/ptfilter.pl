#!/usr/bin/perl
# name:     ptfilter.pl
# process:  Post-process a Profitool OUT file. Called via the SA STOP PROCEDURE
#           parameter
# author:   Simon Taylor
# notes:    This is source-controlled software. Make changes only via the svn
#           repository at: 
#
#           http://trac.accoes.com/trac/browser/trunk/erp/profitool/ptfilter

use strict;
use warnings;

sub mark_time($);

#
# Step 1. Get command line arguments
# Typical line from an IN file looks like:
# $PT_SITE_PATH/shell/ptfilter.pl $OUTF  "RWEXECUTE        " "RWEXECUTE AR AGED BY PM   Post 05/30/00  "
# $PT_SITE_PATH/shell/ptfilter.pl $OUTF  "PRCHECK          " "PRCHECK       Type: SV                   "
#

my $OUTFILE   = $ARGV[0];
my $RPT       = $ARGV[1];
my $RPT_MEMO  = $ARGV[2];
my ($second, $minute, $hour, $day, $month, $year);

#
# Step 2. Check the OUTFILE argument and construct the name of the O_ file
#
if ($OUTFILE !~ m/^OUT(\d{3})/) {
    print qq(\nptfilter: Expected OUTnnn as 1st argument, but saw: $OUTFILE\n);
    exit(2);
}
my $ERRFILE = "O_${1}";
my $fh = append_file ("$ERRFILE");
printf $fh "OUT: $OUTFILE\n";
printf $fh "RPT: $RPT\n";
printf $fh "RPT_MEMO: $RPT_MEMO\n";

#print $fh "in ptfilter.pl num args = $#ARGV\n";
#print $fh "OUTFILE: <$OUTFILE>\n";
#print $fh "RPT: <$RPT>\n";
#print $fh "RPT_MEMO: <$RPT_MEMO>\n";

#
# Step 3. Post-process selected reports
#

SWITCH: {
    if ($RPT_MEMO =~ /^RWEXECUTE COST DIST B-4    /) {
	mark_time("start");
        rwexcute_cost_dist_b_4($OUTFILE);
	mark_time("finish");
        last SWITCH; 
    }


    if ($RPT_MEMO =~ /^RWEXECUTE EMP INIT    /) {
	mark_time("start");
        rwemp_init($OUTFILE);
	mark_time("finish");
        last SWITCH; 
    }
    if ($RPT_MEMO =~ /^RWEXECUTE AR AGED BY PM    /) {
	mark_time("start");
        rwar_aged_by_pm($OUTFILE);
	mark_time("finish");
        last SWITCH; 
    }
    if ($RPT_MEMO =~ /^PRCHECK       Type: SV    /) {
	mark_time("start");
        prcheck_sv($OUTFILE, "check");
	mark_time("finish");
        last SWITCH; 
    }
    if ($RPT_MEMO =~ /^PRNO CHECK    Type: SV    /) {
	mark_time("start");
        prcheck_sv($OUTFILE, "no_check");
	mark_time("finish");
        last SWITCH; 
    }
    if ($RPT_MEMO =~ /^PRCHECK RESTART type: SV  /) {
	mark_time("start");
        prcheck_sv($OUTFILE, "check_restart");
	mark_time("finish");
        last SWITCH; 
    }
    if ($RPT_MEMO =~ /^RWEXECUTE WLR  /) {
	mark_time("start");
        wlr($OUTFILE);
	mark_time("finish");
        last SWITCH; 
    }
    if ($RPT_MEMO =~ /^RWEXECUTE WLR SETUP  /) {
	mark_time("start");
        wlr($OUTFILE);
	mark_time("finish");
        last SWITCH; 
    }
    if ($RPT_MEMO =~ /^PRDIRECT DEPOSIT  PR  /) {
        mark_time("start");
        direct_deposit($OUTFILE);
        mark_time("finish");
        last SWITCH;
    }
}

close ($fh);
exit(0);

#
# Open the supplied pathname in append mode and return the file handle
#

sub append_file {
    my $path = shift;
    local *FH;
    open (FH, ">>$path") or return undef;
    return *FH;
}

#
# Output a start or end timestamp, depending on the 'action' argument
#

sub mark_time($) {
    my ($action) = @_;

    if ($action eq "start") {
	($second, $minute, $hour, $day, $month, $year) = (localtime)[0..5];
        printf $fh " started post-processing: %s-%02d-%02d %02d:%02d:%02d\n",
	       ($year + 1900), ($month + 1), $day, $hour, $minute, $second;
    } else {
        ($second, $minute, $hour, $day, $month, $year) = (localtime)[0..5];
        printf $fh "finished post-processing: %02d-%02d-%02d %02d:%02d:%02d\n",
	       ($year + 1900), ($month + 1), $day, $hour, $minute, $second;
    }
    return;
}

#
# Post-process the RW COST DIST B-4 report (This is the Project Managers
# Cost Distribution report).
#

sub rwexcute_cost_dist_b_4 {
    my $path = shift;
    use Cwd;

    #
    # Only run if we are in the /home/report-cd lfd
    #

    my $dir = cwd();
    print "dir: $dir\n";
    return unless ($dir eq "/home/report-cd" or $dir eq "/home/sunbpo" );

    #
    # Run pm.pl against this report
    #

    system("mkdir pm; cd pm && /usr/local/perl/pm.pl $dir/$path && cd $dir");

    # Compress the report

      system("gzip $path");
    # Email report to afogel@accoes.com if from /home/report-cd LFD ACCO
      
      if ( $dir eq "/home/report-cd") {
           system("mutt -s 'Weekly COST DIST' -a $path.'gz' afogel\@accoes.com < /dev/null");
      }
      if ( $dir eq "/home/sunbpo") {
           system("mutt -s 'Weekly COST DIST' -a $path.'gz' mmerida\@sunbeltcontrols.com < /dev/null");
      }

    # Uncompress back the report

      system("gunzip $path");
}

#
# Post-process the RW AGED BY PM report
sub rwar_aged_by_pm {
    my $path = shift;

    rename ("$path", "${path}.old") or die "ptfilter: Could not rename $path"; 
    open (OFH, "<${path}.old") or die "ptfilter: Could not open ${path}.old"; 
    open (NFH, ">$path") or die "ptfilter: Could not open $path"; 
    while (<OFH>) {
        s/AR AGED RECEIVABLES/AR aged RECEIVABLES/;
        print NFH;
    }
    close (OFH);
    close (NFH);
    unlink ("${path}.old") or die "ptfilter: Could not remove ${path}.old"; 
}

#
# Post-process the RWEXECUTE EMP INIT report. This is the ptfilter.pl
# test case. The filtering done here for this report is for test purposes only.
#

sub rwemp_init {
    my $path = shift;

    rename ("$path", "${path}.old") or die "ptfilter: Could not rename $path"; 
    open (OFH, "<${path}.old") or die "ptfilter: Could not open ${path}.old"; 
    open (NFH, ">$path") or die "ptfilter: Could not open $path"; 
    while (<OFH>) {
        s/Employees and Their Departments /Employees and their departments /;
        print NFH;
    }
    close (OFH);
    close (NFH);
    unlink ("${path}.old") or die "ptfilter: Could not remove ${path}.old"; 
}

#
# Post-process the PR CHECK report (for payroll type 'SV')
#

sub prcheck_sv {
    my ($path, $type) = @_;

    #
    # Call the service_timesheet program
    #
    
    if ($type eq "check") {
        system("/usr/local/perl/service_timesheet/service_timesheet.pl -d -c $path");
    } elsif ($type eq "check_restart") {
        system("/usr/local/perl/service_timesheet/service_timesheet.pl -d -c $path");
    } elsif ($type eq "no_check") {
        system("/usr/local/perl/service_timesheet/service_timesheet.pl -d -n $path");
    }
    return 0;
}

sub wlr {
    my ($outfile) = @_;
    use Cwd;
    my $cwd = getcwd();
    # If we're in a test lfd, run the test version
    if ($cwd =~ m/test/) {
        print "In test\n";
        system("/usr/local/perl/generate_weekly_labor_report_dev/generate_weekly_labor_report.pl $outfile");
    } else {
        print "Not In test\n";
        system("/usr/local/perl/generate_weekly_labor_report/generate_weekly_labor_report.pl $outfile");
    }
    return 0;
}

#------------- DIRECT DEPOSIT ------------------------------------
#
# Post-process the PR DIRECT DEPOSIT report (for payroll LFD pr-1, sunpr, sepayr )
#

sub direct_deposit {

  # my ($y, $m, $d, $h, $mm) = Today();
    my ($sec, $min, $hour, $mday, $mon, $year, $wday, $yday, $dst) = localtime();

    my $ach_name = "ACH" . ($year + 1900) . sprintf("%02d", ($mon + 1)) . sprintf("%02d", $mday);

   #---- ACCO ----
    my $acco_dirdep_file = "/data01/acco.dfd/dirdep/DIR.DEPOSIT.ACCO.121000248.TAPE";
    my $acco_ach_file = "/data01/acco.dfd/dirdep/$ach_name";

   #---- SUNB ----
    my $sunb_dirdep_file = "/data01/acco.dfd/sbdirdep/DIR.DEPOSIT.SUNB.121000248.TAPE";
    my $sunb_ach_file = "/data01/acco.dfd/sbdirdep/$ach_name";

   #---- SUNE ----
    my $sune_dirdep_file = "/data01/sedirdep/DIR.DEPOSIT.SUNE.121000248.TAPE";
    my $sune_ach_file = "/data01/sedirdep/$ach_name";

    my $path = shift;
    use Cwd;

    #
    # Only run if we are in the /home/pr-1 or /home/sunpr or /home/sepayr LFD
    #
  
    my $dir = cwd();
    print "dir: $dir\n";

    return unless ($dir eq "/home/pr-1" or $dir eq "/home/sunpr" or $dir eq "/home/sepayr");

    if ( $dir eq "/home/pr-1") {
         if (-f $acco_dirdep_file) {
              unless (rename($acco_dirdep_file, $acco_ach_file)) {
              error("Could not rename $acco_dirdep_file to $acco_ach_file: $!");
            }
         }
    }  
# }
    if ( $dir eq "/home/sunpr") {
         if (-f $sunb_dirdep_file) {
              unless (rename($sunb_dirdep_file, $sunb_ach_file)) {
              error("Could not rename $sunb_dirdep_file to $sunb_ach_file: $!");
            }
         }
    }  
   
    if ( $dir eq "/home/sepayr") {
         if (-f $sune_dirdep_file) {
              unless (rename($sune_dirdep_file, $sune_ach_file)) {
              error("Could not rename $sune_dirdep_file to $sune_ach_file: $!");
            }
         }
    }  
}
