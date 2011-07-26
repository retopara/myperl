#!/usr/bin/perl

use strict;
use warnings;

#  original folder and destination folder
my $orig_dir = "/home/retopara/github/test/test_orig";
my $dest_dir = "/home/retopara/github/test/test_dest";

#  lines of input file
my $line1 = "3  2  2  2";
my $line2 = "//NPAR  NONE  NLEV  NCONE  alpha  beta";

#  vary of input parameters
my @alpha = qw\0.0 0.1 0.2 0.3 0.4 0.5\;
my @beta = qw\0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0\;

foreach my $curr_beta (@beta)
{
	foreach my $curr_alpha (@alpha)
	{
		my $curr_dest = $dest_dir."_b".$curr_beta."_a".$curr_alpha;
#    print "$curr_dest\n";

		#  delete folder if it already exists
		if (-d $curr_dest)
		{
			system ("rm -r $curr_dest");
		}

		#  cp dir
		my $cmd1 = "cp -r ".$orig_dir." ".$curr_dest;
#    print "$cmd1\n";
		system ($cmd1);

		#  write input file
		my $curr_outfile = $curr_dest."/target_func_input.txt";
#    print "$curr_outfile\n";
		open (my $outfile, ">", $curr_outfile) or die "Could not open file target_func_input.txt: $!";
		my $out_line1 = $line1."  ".$curr_alpha."  ".$curr_beta;
		print {$outfile} "$out_line1\n";
		print {$outfile} "$line2\n";
		close $outfile; 
	}
}

