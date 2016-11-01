#!/bin/bash

# Verified account and password, access to file the root directory of the statistics

# Authentication information
echo "Account: liuwei"
echo "Passwd : liuwei"

# Need to statistics document root directory
# current work-directory
CURDIR=`pwd`
DSTDIR=learn-code

cd ~/${DSTDIR}

./lwc .

cd ${CURDIR}
