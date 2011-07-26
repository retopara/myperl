#!/bin/bash
for file in `ls -p | grep discord3`; do
	test -d $file && ( 
num=`cat ${file}/matrix.txt | tail -5 | sed -n '/fvec_min/p' | awk '{print $3}'`
alpha=`cat ${file}/matrix.txt | tail -5 | sed -n '/alpha/p' | awk '{print}'`
echo $file $alpha $num
)
done
