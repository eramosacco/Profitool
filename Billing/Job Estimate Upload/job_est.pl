#!/usr/bin/perl
# name:     job_est.pl  
# process:  Upload JOB.ESTIMATE  file to Profitool via excel file
#                                       
# author:                         
# revision: $Id: job_est.pl,v 1.0 2013/10/17 07:15:04 elr Exp $

#use strict;
use warnings;
use Unisolve::Config;
use Unisolve::Log;
use PT::Report;
use MIME::Lite;
use Date::Calc qw(Today Day_of_Week Add_Delta_Days);
use Data::Dumper;
use Getopt::Std;
my $prog = "job_est.pl";
my $rc;
my $origlfd="";

#$opt_d = 0;

$origlfd=`pwd`;

chdir $origlfd;

sub rename_old_datafile($$);
sub send_email($$);
sub run_job_est_report($$);
sub get_dates();
sub setup($);
sub error($$$);

#
# Process
#
#
# 1. Read configuration values and load_job_estimate log file
#

my ($conf, $log) = setup('/usr/local/perl/load_job_estimate/load_job_estimate.conf');

    print "Step-1. Renaming old JOB ESTIMATE file...\n";
    rename_old_datafile($conf, $log);

#
# 2. Run pt make-job-estimate PT prog
#

  $log->log("Step-2. Loading JOB ESTIMATE file");
  print "Step-2. Loading JOB ESTIMATE file...\n";
  run_job_est_report($conf, $log);

# 3. Send confirmation email

  $log->log("Step-3. Sending confirmation email");
  print "Step-3. Sending confirmation email\n";
  send_email($conf, $log);

$log->log("Done " . localtime());
print "Done...\n";
print " \n";
print "Please type Y to continue..\n";
while (<>) {
             chomp;
             unless (/^y/i) {
                 print "Please type the letter Y...\n";
                             } else {
                               exit;
                                    }
           }

exit 0;

#-------------------------------------------------------------
# --- Subroutines ---

sub rename_old_datafile($$) {
  my ($conf, $log) = @_;
  
  use File::Basename;
  use File::Copy;

  my $path = shift;
  use Cwd;

  my $origlfd = cwd();

  my $old_output_file3 = $conf->{output_file3};
  my $input_file = $conf->{input_file};
  my $path3 = $origlfd . $old_output_file3; 

# my ($name3, $path3, $suffix3) = fileparse($conf->{output_file3}, qr{\.[^\.]+});
my ($y, $m, $d, $h, $mm) = Today();
my ($sec, $min, $hour, $mday, $mon, $year, $wday, $yday, $dst) = localtime();

  my $new_name3 = $path3 . $y . sprintf("%02d", $mon) . sprintf("%02d", $mday) . sprintf("%02d", $hour) . sprintf("%02d", $min);
  
 if (-f $path3) {
    $log->log("Renaming $path3 to $new_name3");
    unless (move($path3, $new_name3)) {
      error($conf, $log, "Could not rename $path3 to $new_name3: $!");
   }
  }

}

sub send_email($$) {
 my ($conf, $log) = @_;
 my $msg = MIME::Lite->new(
   To => $conf->{email},
   From => $conf->{email},
   Subject => 'JOB ESTIMATE Upload',
   Data => "JOB ESTIMATE file Upload to Profitool has run to completion.",
 );

#
#--- Attach output file to email
#
#  $msg->attach(Type     => 'TEXT',
#               Path     => "$conf->{output_file1}", "$conf->{output_file2}",
#               Filename => "output1", "output2"
#      );

  # send email
  $msg->send() or error($conf, $log, "Could not send JOB ESTIMATE file Upload email: $!");
  }

sub run_job_est_report($$) {
  my ($conf, $log) = @_;
  my $dates = get_dates();
  my $rc;
  my $input_file = $conf->{input_file};
  my $output_file3 = $conf->{output_file3};
# my $lfd = $conf->{lfd};

  my $origlfd=`pwd`;
# my $lfd = $origlfd;

  chdir $origlfd;

  chomp($origlfd);
  chomp($output_file3);
  my $archive_lfd = "$origlfd"."$output_file3";
              
# my $report3 = 'pt make-job-estimate';
  
  chomp($input_file);
  my $load_file3 = "$origlfd"."/"."$input_file";

  if (-f $input_file) {
       print "JOB ESTIMATE exist...now loading \n";
       system "pt make-job-estimate";
       move($input_file, $archive_lfd);
     }
  else {
       print ("There is no JOB.ESTIMATE file to upload.\n");
      $log->log("There is no JOB.ESTIMATE file to upload: $!");
       }
  return ($conf, $log);

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
   Subject => 'ERROR: JOB ESTIMATE Upload',
   Data => "The JOB ESTIMATE Upload to Profitool has failed: $error at line $caller[2] in $caller[1].  Please check the log file $conf->{logfile}",
 );
 $msg->send() or $log->log_and_exit("Could not upload JOB ESTIMATE error email: $!");
   $log->log_and_exit($error);
}

#-------------------------------------------------------------
# $Log: job_est.pl,v $
#
# 2013/10/17 - elr
# Initial version                 
#
# 2015/01/26 - elr
# Make script compatible with multiple LFDs.
