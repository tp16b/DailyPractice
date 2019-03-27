#!/bin/sh

# 获取用户输入
PATHNAME=$1

if [ ! $# -eq 1 ];then
	echo "Usage: please entry one param"
else
	# 判断是否是文件
	if [ -f $PATHNAME ]; then
		echo $PATHNAME "file has existed..."
	else 
		if [ -d $PATHNAME ];then
			echo $PATHNAME ": directory has existed..."
		else	
			mkdir -p $PATHNAME
		fi
	fi
fi
