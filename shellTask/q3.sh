#!/bin/bash

# 拿到当前路径下所有文件的md5值
find $@ -not -empty -type f | xargs md5sum | sort -k1 |uniq -w  32 --all-repeated=separate 

