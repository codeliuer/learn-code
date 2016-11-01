#! /bin/bash

CURRENT=`pwd`

echo "${CURRENT#/}"
if [ "${CURRENT#/}" = "Users/weiliu/learn-code/shell/01" ];then
    echo "equal"
fi

RELATIVE=$1
echo "${RELATIVE#*/}"	#delete '/' left all character
echo "${RELATIVE#/}"	#delete left '/'

STRING="string"
echo ${#STRING}

PWD=/home/liuwei/home
echo "${PWD#*/\/}"
