# compiler src file

# 

CC=gcc

MID_FILE =
MID_FILE += main.o

SRC_FILE=
SRC_FILE=main.c

EXECFILE=exec

${EXECFILE}:${MID_FILE}
	${CC} -o ${EXECFILE} ${SRC_FILE}

${MID_FILE}:${SRC_FILE}
	@echo "begin compiler"
	${CC} -c ${SRC_FILE}

clean:
	rm -rf ${MID_FILE} ${EXECFILE}
