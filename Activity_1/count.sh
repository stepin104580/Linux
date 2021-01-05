#!/bin/bash
#!==> Shabang
echo the no of lines in a.cpp
wc -l < a.cpp

echo the no of empty lines in a.cpp
#grep -cvP '\S' a.cpp
grep -c ^$ a.cpp

count=0
one=1
while IFS= read -r line
do
   len=`expr length "$line"`
   if [ $len -eq $one ]
   then
     count=$((count+1))
   fi
done < a.cpp
echo "$count"

