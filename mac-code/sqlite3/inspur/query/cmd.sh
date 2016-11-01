# !/bin/bash

# compile source file
gcc *.c -lsqlite3

# exec 
./a.out

# clean
rm a.out
