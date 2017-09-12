#!/home/cmissa/perl5/perlbrew/perls/perl-5.22.0/bin/perl


use strict;
use warnings;

use Unisolve::Config;
use MIME::Lite;



# Setup
my ($conf) = setup();

## print " Address $conf->{error_email_address}\n";
## print " Subject $conf->{error_email_subject}\n";
## print "    smtp $conf->{smtp}\n";

# Email
send_error_email($conf);

exit 0;


sub send_error_email {
    my ($conf) = @_;

    my $msg = MIME::Lite->new(
        To      => $conf->{error_email_address},
        From    => 'autoisrewrite_error_monitor@accoes.com',
        Subject => $conf->{error_email_subject},
        Data    => $conf->{error_email_body},
        Type    => 'TEXT',
    );
	
	MIME::Lite->send('smtp', $conf->{smtp}, Timeout => 60);
	$msg->send() or exit 1;

	return;
}

sub setup {
#    my $conf = Unisolve::Config->new(conffile => '/home/bianca/clients/acco/autoisrw/send_error_email.conf'); 
    my $conf = Unisolve::Config->new(conffile => './send_error_email.conf'); 
    my $conf_error = $conf->check_config(['error_email_address', 'error_email_subject', 'error_email_body', 'smtp']);
    exit 1 if ($conf_error);

    return $conf;
}
