#!/bin/bash
#for folder in `ls -p | grep /`; do
for folder in `ls -p | grep sample.*_new`; do
	cd $folder
	echo "enter $folder"
	qsub openmpi.pbs
	cd ..
done
