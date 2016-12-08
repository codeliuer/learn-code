#! /bin/bash

#echo ${PATH} | sed 's/^:/.:/ \
#				    s/::/:.:/g \
#					s/:$/:./ \
#					s/:/ /g'

echo ${PATH} | sed 's/::/:.:/g /$:/.:/'
