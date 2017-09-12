#!/root/perl5/perlbrew/perls/perl-5.22.0/bin/perl
#!/home/cmissa/perl5/perlbrew/perls/perl-5.22.0/bin/perl
# name:    is_odd_day.pl
# process: Returns 0 (Unix shell success) if the current day of the year is odd, or 1 (failure) otherwise
#          Used by ptautoisrw (in test mode only)
# author:  Simon Taylor
# usage:
#          Command line:
#              $ ./is_odd_day.pl
#              $ echo $?
#              1
#

use strict;
use warnings;
use DateTime;

my $dt = DateTime->now(time_zone=>"local");
my $day = $dt->day;

if ($day % 2 == 1) {
    exit 0; # An odd day number, so success
} else {
    exit 1; # An even day number, so failure
}

