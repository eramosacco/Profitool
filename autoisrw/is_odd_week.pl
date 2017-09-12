#!/root/perl5/perlbrew/perls/perl-5.22.0/bin/perl
#!/home/cmissa/perl5/perlbrew/perls/perl-5.22.0/bin/perl
# name:    is_odd_week.pl
# process: Returns 0 (Unix shell success) if the current week of the year is odd, or 1 (failure) otherwise
#          Used by ptautoisrw
# author:  Simon Taylor
# usage:
#          Command line:
#              $ ./is_odd_week.pl
#              $ echo $?
#              1
#
#          Shell script:
#              See test_is_odd_week.sh


use strict;
use warnings;
use DateTime;

my $dt = DateTime->now(time_zone=>"local");
my $week_of_year = $dt->week_number;

if ($week_of_year % 2 == 1) {
    exit 0; # An odd week number, so success
} else {
    exit 1; # An even week number, so failure
}

