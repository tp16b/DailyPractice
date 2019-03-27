#!/bin/bash

cat q5.log | gawk '{print $s=gensub(/[^A-Z0-9]+/,"","g",$0);}'| gawk '{print $s=gensub(/[,]+/, " ","g")}'
