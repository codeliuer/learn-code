#! /bin/bash

DST_CODE=main.c
#SRC_CODE={date.c error.c get.c wc_main.c write.c}

GCC=gcc

CMD=lwc
LIBOBJ=libcommon.so
LIBNAME=common

# the configuration that compiling search path 
export LIBRARY_PATH=.:${LIBRARY_PATH}

# the configuration that run-time search path
export LD_LIBRARY_PATH=.:${LD_LIBRARY_PATH}

# source file compiled product libcommon.so
# ${GCC} -fPIC -shared -o${LIBOBJ} date.c error.c get.c wc_main.c write.c

# main.c compiled lwc command
# ${GCC} -rdynamic -o${CMD} ${DST_CODE} -ldl
${GCC} -o${CMD} main.c date.c error.c get.c wc_main.c write.c -ldl

# root
chown root ${CMD}
chmod u+s ${CMD}

./${CMD} ${1}

# exec object file
#for arg in "$@"
#do
#    ./${CMD} ${arg}
#done
