#!/bin/bash
count=0

cat /home/zhenghua/file.txt | while read line
do
	let ++count;
	if [ $count -eq 9 ]
		then echo $line
	fi
done
