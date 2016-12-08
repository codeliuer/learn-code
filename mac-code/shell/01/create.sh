#! /bin/bash

echo "create many dir :"

for (( i=1; i<=3; i++))
do
	./expect.sh ${i}
	echo "create  $?"
done
