#!/bin/bash
# 从下面日志获取flightnum值和main flightnum值（提示gawk gensub函数的使用）
# 日志：
# flightnum is CA1230，main flightnumMU1230
# flightnum is MU1111，main flightnumCA1111
# 输出：
# CA1230 MU1230
# MU1111 CA1111

echo "使用gensub"
gawk -F ',' '{print gensub("[a-z]+","","g",$1)" "gensub("[a-z]+","","g",$2)}' log.txt
echo ""
echo "使用match+sub+substr"
gawk '{a = "" data = $0
while(match( data ,/[A-Z]{2}[0-9]{4}/) > 0) {
    a = a" "substr(data, RSTART, RLENGTH )
    sub(/[A-Z]{2}[0-9]{4}/,"",data)
}
if(length(a)>=1){
    a = substr(a,2)
}
print a
}' log.txt
