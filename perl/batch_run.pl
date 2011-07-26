#!/usr/bin/perl

use strict;
use warnings;

#  original folder and destination folder
my $orig_dir = "/home/retopara/github/test/test_orig";
my $dest_dir = "/home/retopara/github/test/test_dest";

#  vary of input parameters
my @alpha = qw\0.0 0.1 0.2 0.3 0.4 0.5\;
my @beta = qw\0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0\;

foreach my $curr_beta (@beta)
{
	foreach my $curr_alpha (@alpha)
	{
		my $curr_dest = $dest_dir."_b".$curr_beta."_a".$curr_alpha;
    print "cd $curr_dest\n";

		system ("cd $curr_dest");
		system ("mkdir newfolder");
		system ("cd -");
	}
}

