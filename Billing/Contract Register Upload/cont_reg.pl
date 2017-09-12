#!/usr/bin/perl
# name:     cont_reg.pl 
# process:  Upload cont_reg reg1 file to Profitool via cron
#                                       
# author:   elr                   
# revision: $Id: cont_reg.pl,v 1.0 2013/03/04 07:15:04 elr Exp $

#use strict;
use warnings;
use Unisolve::Config;
use Unisolve::Log;
use PT::Report;
use MIME::Lite;
use Date::Calc qw(Today Day_of_Week Add_Delta_Days);
use Data::Dumper;
use Getopt::Std;
my $prog = "cont_reg.pl";
my $rc;

#$opt_d = 0;

chdir "/home/billing";

sub rename_old_datafile($$);
#sub send_email($$);
sub run_cont_report($$);
sub get_dates();
sub setup($);
sub error($$$);

#
# Process
#
#
# 1. Read configuration values and cont_reg log file
#

my ($conf, $log) = setup('/usr/local/perl/cont_reg/cont_reg.conf');

$log->log("Run with @ARGV");
print "Run with @ARGV\n";
$log->log("Deleting old outfile");
delete_old_outfile($conf, $log);
rename_old_datafile($conf, $log);

my %opts;
getopts('f:', \%opts);

#
# 2. Run the INfile if required
#

if ($opts{f}) {
  # We don't run the in file if we have been given a file
  print "Not running IN file, we have a file to process $opts{f}\n";
} else {
  $log->log("Running Profitool Report");
  print "Running IN file\n";
  run_cont_report($conf, $log);
}

#

# $log->log("Sending confirmation email");
# print "Sending confirmation email\n";
# send_email($conf, $log);

$log->log("Done " . localtime());
print "Upload done ... " . localtime();
exit 0;

#-------------------------------------------------------------
# Subroutines

sub delete_old_outfile {
  my ($conf, $log) = @_;
  my $outfile1 = $conf->{lfd} . 'OUT' . $conf->{report_no1};
  my $outfile2 = $conf->{lfd} . 'OUT' . $conf->{report_no2};
  my $o_file1 = $conf->{lfd} . 'O_' . $conf->{report_no1};
  my $o_file2 = $conf->{lfd} . 'O_' . $conf->{report_no2};
  if (-f $outfile1) {
    unless (unlink($outfile1)) {
      error($conf, $log, "Could not unlink $outfile1: $!");
    }
  }
  if (-f $o_file1) {
    unless(unlink($o_file1)) {
      error($conf, $log, "Could not unlink $o_file1: $!");
    }
  }

  if (-f $outfile2) {
    unless (unlink($outfile2)) {
      error($conf, $log, "Could not unlink $outfile2: $!");
    }
  }
   
  if (-f $o_file2) {
    unless(unlink($o_file2)) {
      error($conf, $log, "Could not unlink $o_file2: $!");
    }
  }
}

sub rename_old_datafile($$) {
  my ($conf, $log) = @_;
  
  use File::Basename;
  use File::Copy;

  my $old_output_file1 = $conf->{output_file1};
  my $old_output_file2 = $conf->{output_file2};
  my $old_output_file3 = $conf->{output_file3};
  my ($name1, $path1, $suffix1) = fileparse($conf->{output_file1}, qr{\.[^\.]+});
  my ($name2, $path2, $suffix2) = fileparse($conf->{output_file2}, qr{\.[^\.]+});
  my ($name3, $path3, $suffix3) = fileparse($conf->{output_file3}, qr{\.[^\.]+});
my ($y, $m, $d, $h, $mm) = Today();
my ($sec, $min, $hour, $mday, $mon, $year, $wday, $yday, $dst) = localtime();

  my $new_name1 = $path1 . $y . sprintf("%02d", $mon) . sprintf("%02d", $mday) . sprintf("%02d", $hour) . sprintf("%02d", $min) . '_' . $name1 . $suffix1;

  my $new_name2 = $path2 . $y . sprintf("%02d", $mon) . sprintf("%02d", $mday) . sprintf("%02d", $hour) . sprintf("%02d", $min) . '_' . $name2 . $suffix2;

  my $new_name3 = $path3 . $y . sprintf("%02d", $mon) . sprintf("%02d", $mday) . sprintf("%02d", $hour) . sprintf("%02d", $min) . '_' . $name3 . $suffix3;
  
  if (-f $old_output_file1) {
    $log->log("Renaming $old_output_file1 to $new_name1");
    unless (move($old_output_file1, $new_name1)) {
      error($conf, $log, "Could not rename $old_output_file1 to $new_name1: $!");
    }
  }

  if (-f $old_output_file2) {
    $log->log("Renaming $old_output_file2 to $new_name2");
    unless (move($old_output_file2, $new_name2)) {
      error($conf, $log, "Could not rename $old_output_file2 to $new_name2: $!");
    }
  }

 if (-f $old_output_file3) {
    $log->log("Renaming $old_output_file3 to $new_name3");
    unless (move($old_output_file3, $new_name3)) {
      error($conf, $log, "Could not rename $old_output_file3 to $new_name3: $!");
   }
  }

}

#sub send_email($$) {
#my ($conf, $log) = @_;
#my $msg = MIME::Lite->new(
#  To => $conf->{email},
#  From => $conf->{email},
#  Subject => 'Contract Register Upload',
#  Data => "Contract Register Upload to Profitool has run to completion."
#);

#
#--- Attach output file to email
#
#  $msg->attach(Type     => 'TEXT',
#               Path     => "$conf->{output_file1}", "$conf->{output_file2}",
#               Filename => "output1", "output2"
#      );

  # send email
# $msg->send() or error($conf, $log, "Could not send Contract Register Upload email: $!");
# }

#sub parse_dde_report($$$) {
# my ($conf, $log, $file) = @_;

# my $outfile;
# if ($file) {
#   $outfile = $file;
# } else {
#   $outfile = $conf->{lfd} . 'OUT' . $conf->{report_no};
# }

# unless (-f $outfile) {
#   error($conf, $log, "Couldn't find outfile $outfile");
# }

# open (REPORT, $outfile) or error($conf, $log, "Couldn't open outfile $outfile: $!");
# open (OUTPUT, ">>$conf->{output_file}") or error($conf, $log, "Couldn't open output file $conf->{output_file}: $!");
# my %dates;
# while (my $line = <REPORT>) {
#   $line =~ s/\s+;/;/g;
#   $line =~ s/;\s+/;/g;
#   if ($line =~ m:^([^;]*;){6}(\d+/\d+/\d+);:) {
#     my $date = $2;
#     if (!$dates{$date}) {
#	my @date_array = split("/", $date);
#	my $dow = Day_of_Week('20' . $date_array[2], $date_array[0], $date_array[1]);
#$dates{$date} = $dow;
#     }
#    #$line =~ s:^(([^;]*;){6})\d+/\d+/\d+;:$1;$dates{$date};:;
#     $line =~ s:^(([^;]*;){6})\d+/\d+/\d+;:$1$dates{$date};:;
#   }
#   $line =~ s/;/\t/g;
#   print OUTPUT $line . "\n";
# }

# close OUTPUT;
# close REPORT;
#}

sub run_cont_report($$) {
  my ($conf, $log) = @_;
  my $infile1 = $conf->{lfd} . 'IN' . $conf->{report_no1};
  my $infile2 = $conf->{lfd} . 'IN' . $conf->{report_no2};
  my $dates = get_dates();
  my $rc;
  
  my $report = PT::Report->new(
     template1 => $conf->{infile_template1},
     infile1 => $infile1 
   );

 # my $report2 = PT::Report->new(
 #   template2 => $conf->{infile_template2},
 #   infile2 => $infile2 
 # );

  # my $report1 = "IN200";
  my $report = $infile1;
  # my $report2 = "IN201";
  my $report2 = $infile2;
  my $report3 = 'pt make-job-estimate';
  my $load_file1 = "/home/billing/cont-reg-reg1.txt";
  my $load_file2 = "/home/billing/cont-reg-reg2.txt";
  my $load_file3 = "/home/billing/JOB.ESTIMATE";

chdir "/home/billing";

if (-f $load_file1) {
#  $rc = system "ksh IN000";
    unlink IN000;
   system "cp -f \/usr\/local\/perl\/cont_reg\/cont_reg1_template IN000";
   system "pt IN000";
#  $report->run($conf->{lfd})|| error($conf, $log, "There is no cont reg reg1 file to upload: $!");
}

if (-f $load_file2) {
 #   $rc = system "ksh IN201";
   unlink IN000;
   system "cp -f \/usr\/local\/perl\/cont_reg\/cont_reg2_template IN000";
   system "pt IN000";
  #  $report2->run($conf->{lfd})|| error($conf, $log, "There is no cont reg reg2 file to upload: $!");
}

if (-f $load_file3) {
  #  $rc = system "pt make-job-estimate";
     system "pt make-job-estimate";
     unless (move("/home/billing/JOB.ESTIMATE", "/home/billing/archive/JOB.ESTIMATE")) {
    error($conf, $log, "Could not moved  RJOB.ESTIMATE file: $!");
} 
  # $report3->run($conf->{lfd})|| error($conf, $log, "There is no JOB ESTIMATE file to upload: $!");
}

}

sub get_dates() {
  # Report date is Tuesday this week
  # Report period is Wednesday last week
  # Begin date is Wednesday last week
  my %dates;
  my @today = Today();
  my $dow = Day_of_Week(@today);
  my @tuesday;
  if ($dow == 2) {
    @tuesday = @today;
  } elsif ($dow  == 1) {
    @tuesday = Add_Delta_Days(@today, 1);
  } else {
    @tuesday = Add_Delta_Days(@today, (2 - $dow));
  }
  my @wednesday = Add_Delta_Days(@tuesday, -6);
  $dates{report_date} = sprintf("%u%02u%02u", @tuesday);
  $dates{report_month} = sprintf("%02u", $tuesday[1]);
  $dates{report_day} = sprintf("%02u", $tuesday[2]);
  ($dates{report_year} = $tuesday[0]) =~ s/..(..)$/$1/;
  $dates{report_date_display} = sprintf("%02u/%02u/%02u", $dates{report_month}, $dates{report_day}, $dates{report_year});

  $dates{period_date} = sprintf("%u%02u%02u", @wednesday);
  $dates{period_month} = sprintf("%02u", $wednesday[1]);
  $dates{period_day} = sprintf("%02u", $wednesday[2]);
  ($dates{period_year} = $wednesday[0]) =~ s/..(..)$/$1/;

# $dates{begin_date} = sprintf("%u%02u%02u", @wednesday);
# $dates{begin_month} = sprintf("%02u", $wednesday[1]);
# $dates{begin_day} = sprintf("%02u", $wednesday[2]);
# ($dates{begin_year} = $wednesday[0]) =~ s/..(..)$/$1/;

  return \%dates;
}

sub setup($) {
  my ($conffile) = @_;
  my $conf = Unisolve::Config->new(
    conffile => $conffile
  );
  # my $err = $conf->check_config(['logfile', 'report_no1', 'report_no2', 'lfd', 'email']);
  die $err if ($err && !$conf->{logfile});

  my $log = Unisolve::Log->new(
    filename => $conf->{logfile},
    indent => 1,
  );
   $log->start_message();
   if ($err && !$conf->{email}) {
    $log->log_and_exit("Fatal Error: Could not find configuration paramter $err in $conffile");
     } elsif($err) {
    error($conf, $log, "Fatal Error: Could not find configuration paramter $err in $conffile");
    }
    return ($conf, $log);
}

sub error($$$) {
  my ($conf, $log, $error) = @_;
  my @caller = caller();

my $msg = MIME::Lite->new(
   To => $conf->{email},
   From => $conf->{email},
   Subject => 'ERROR: Contract Register Upload',
   Data => "The Contract Register Upload to Profitool has failed: $error at line $caller[2] in $caller[1].  Please check the log file $conf->{logfile}",
 );
 $msg->send() or $log->log_and_exit("Could not send Contract Register error email: $!");
   $log->log_and_exit($error);
}

#-------------------------------------------------------------
# $Log: cont_reg.pl,v $
#
# 2013/03/04 - elr
# Initial version                 
#
