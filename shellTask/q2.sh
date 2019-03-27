#!/bin/bash

file1=$1
file2=$2

if [ ! $# -eq 2 ];then
	echo "Usage: please entry two files"
else
	if [ ! -f $file1 ];then
		echo "$file1 不是一个文件"
		exit
	elif [ ! -f $file2 ];then
		echo "$file2 不是一个文件"
		exit
	fi

	# 拿到空行数目
	num1=$(grep "^\s*$" $file1 | wc -l)	
	num2=$(grep "^\s*$" $file2 | wc -l)	
	if [ $num1 -gt $num2 ];then
		echo "$file1 文件空行数目较多,有：$num1" 
	elif [ $num1 -lt $num2 ];then
		echo "$file2 文件空行数目较多,有：$num2" 
	else
		echo "$file1 和 $file2 空行数目一样"
	fi
	# 拿到文件行数
	n1=$(wc -l $file1 | awk '{print $1}')
	n2=$(wc -l $file2 | awk '{print $1}')
	if [ $n1 -gt $n2 ];then
		echo "$file1 总行数较多,有：$n1" 
	elif [ $n1 -lt $n2 ];then
		echo "$file2 总行数较多,有：$n2" 
	else
		echo "$file1 $file2 总行数一样,有：$n1" 
	fi
fi

