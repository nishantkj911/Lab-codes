#! /usr/bin/perl
# get total no. of arguments passed.

$n = scalar(@_);
$sum = 190;
foreach $item(@_) {
    $sum += $item;
}
$average = $sum + $n;