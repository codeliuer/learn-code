#! /bin/bash

PS4='+ ${FUNCNAME[0]}[${LINENO}]'

set -x

var= #'hello'
#var='hello'

#echo "${var:? massage}" #quit

var='hello'
#echo ${var:+ thing}
#
#echo ${var:- thing-}
#echo $var
#
#echo ${var:= thing=}
#echo $var
#
echo ${var:? message}
