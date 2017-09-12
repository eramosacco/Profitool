#!/usr/bin/perl -w


use strict;
#use warnings;

use Getopt::Std;
use Mail::Sender;

my $layout = "";
my $layoutname = "Portrait";
my $points = "-p 10.0";
my $attach = "";
my $email = "";
my $subject1 = "Profitool Report";
my $subject2 = "Profitool File";
my $fromaddr = "cmismn\@accoes.com";
my $domain = "accoes.com";
my $attachtype = "1";
    # 1 - pdf file
    # 2 - text file
    # 3 - both pdf and text file
    # 4 - force pdf (overwrite existing PDF file)
my $filelist = "";
my $rptnum = "";
my $ret;
my $smtpserver = "localhost";
my $ascii2pdf = "/usr/local/bin/ascii2pdf";

my %option = ();
getopts("w:f:p:e:s:t:LP", \%option);

if ($option{w}) { 
  $fromaddr = $option{w};
  $fromaddr =~ s/\ //g;
  #print STDERR "sender is $fromaddr\n";
}

if ($fromaddr !~ /\@/) {
  $fromaddr .= "\@$domain";
}

# landscape mode?
if ($option{L}) { 
  $layout = "-l";
  $layoutname = "Landscape";
  $points = "-p 9.0";
  #print STDOUT "layout is $layout\n";
}

# font Point size
if ($option{p}) {
  $points = "-p " . $option{p};
  #print STDOUT "points is $points\n";
}

# File to attach
if ($option{f}) {
  $attach = $option{f};
  #print STDOUT "attach is $attach\n";
}

# email address
if ($option{e}) {
  $email = $option{e};
  #print STDOUT "email is $email\n";
}

# subject
if ($option{s}) {
  $subject1 = $option{s};
  $subject2 = $option{s};
  #print STDOUT "subject is $subject1\n";
  #print STDOUT "subject is $subject2\n";
}

# attachment type
if ($option{t}) {
    $attachtype = $option{t};
    #print STDOUT "attachment type is $attachtype\n";
}

  

if ($attachtype == 1 || $attachtype == 4) {
    $filelist = $attach . ".pdf";
    if ($attachtype == 4 || !-e $filelist) {
        system("$ascii2pdf $layout $points -t 17 -s 18 $attach");
    }
    if ($attach =~ /OUT([0-9]+)/) {
        $rptnum = $1;
    }
    else {
        $rptnum = 1000;
    }
}
elsif ($attachtype == 2) {
    $filelist = $attach . ".txt";
    system("cp -f $attach $filelist");
    if ($attach =~ /OUT([0-9]+)/) {
        $rptnum = $1;
    }
    else {
        $rptnum = 1000;
    }
}
elsif ($attachtype == 3) {
    $filelist = $attach . ".txt";
    system("cp -f $attach $filelist");
    if (!-e "$attach.pdf") {
        system("$ascii2pdf $layout $points -t 17 -s 18 $attach");
    }
    $filelist = $filelist . ", " . $attach . ".pdf";
    if ($attach =~ /OUT([0-9]+)/) {
        $rptnum = $1;
    }
    else {
        $rptnum = 1000;
    }
}
else {
    print STDOUT "Invalid attacment type $attachtype\n";
    exit 0;
}

my $rc = my $sender = new Mail::Sender {
    smtp => $smtpserver,
    from => $fromaddr
};

if ($rc >= 0) {
    if ($rptnum <= 999) {
        $ret = ref ($sender->MailFile({to => "$email",
        subject => "$subject1",
        msg => "Attached is a Profitool report you requested:\n\nReport Number: $rptnum \nDescription: $subject1\nFile: $filelist \nLayout: $layoutname\n\n\n",
        file => "$filelist"}));
    }
    else {
        $ret = ref ($sender->MailFile({to => "$email",
        subject => "$subject2",
        msg => "Attached is the file you requested via Profitool:\n\nDescription: $subject2\nFile: $filelist \n\n\n",
        file => "$filelist"}));
    }
    if (! $ret)
    {
        print "Sender Module Return Code: $ret \n";
        warn ("Return code from \" $sender->{error} \" mailfile is " . $Mail::Sender::Error . "\n");
    }
} 
else {
    print "There is a problem with Mail::Sender \n";
    print "Return Code: $rc \n";
    print "Run perldoc Mail::Sender for a definition of the return code. \n"
}

exit 0;
