#!/usr/bin/perl
use POSIX qw/strftime/;

print "hello, world!\n";
print strftime('%Y%m%d-%H%M%S',localtime);
print "\n";
