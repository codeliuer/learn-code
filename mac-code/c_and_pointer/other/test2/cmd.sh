# !/bin/bash

GCC=gcc

FPIC=-fPIC
SHARED=-shared
DYNAMIC=-rdynamic

ERR_OBJ=liberror.so
PLG_OBJ=libplugin.so
OTH_OBJ=libother.so
COM_OBJ=libcommon.so

ERR_NAME=error
OTH_NAME=other
COM_NAME=common
PLG_NAME=plugin

MAIN=main

# the configuration link the search path that
# current work directory is search directory
export LIBRARY_PATH=.:${LIBRARY_PATH}

# the configuration execute the search path that 
# current work directory is search directory
export LD_LIBRARY_PATH=.:${LD_LIBRARY_PATH}

# compile error.c to liberror.so
${GCC} ${FPIC} ${SHARED} -o${ERR_OBJ} ./error.c

# compile plugin.c to libplugin.so
${GCC} ${FPIC} ${SHARED} -o${PLG_OBJ} ./plugin.c -l${ERR_NAME} 

# compile other.c to libother.so
${GCC} ${DYNAMIC}  ${FPIC} ${SHARED} -o${OTH_OBJ} ./other.c -l${ERR_NAME} -ldl
 
# compile common.c to libcommon.so
${GCC} ${DYNAMIC} ${FPIC} ${SHARED} -o${COM_OBJ} ./common.c -l${ERR_NAME} -ldl

# compile main.c to main, run ./main --parameter
${GCC} ${DYNAMIC} -o${MAIN} ./main.c -l${ERR_NAME} -ldl
