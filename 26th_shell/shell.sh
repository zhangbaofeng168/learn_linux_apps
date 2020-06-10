#!/bin/bash

#2.2
a="hello word"
b=5
echo "A is " $a
echo "B is " $b

#2.3
echo "number of val:" $#
echo "value of val"   $*
echo "name of scipt"  $0
echo "value of val1"  $1
echo "value of val2"  $2

#2.4
val1=20
val2=10
val3=`expr $val1 / $val2`
val4=`expr $val1 + $val2`
echo $val3
echo $val4

#2.5.1
var5=10
if [ $var5 -gt 5 ]
then
    echo "the val is greater than 5"
fi

#2.5.2
list="Sun Mon Tue Wed Thur Fri Sat"
for day in $list
do
	echo $day
done

#2.5.3
var6=5
while [ $var6 -gt 0 ]
do
	echo $var6
	var6=`expr $var6 - 1`
done