#! /bin/bash

input='1.c'


function add()
{
	num=`expr $num + 1`
}

function total()
{
	cat ${input} | while read line
	do
		add
	done
}

num=0
total
echo ${num}
