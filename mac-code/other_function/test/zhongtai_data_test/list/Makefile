# mul

SRC=list
MAN=main
OBJ=test
GCC=gcc


${OBJ}:${MAN}.o ${SRC}.o
	${GCC} -o $@ $<

main.o:main.c
	${GCC} -c main.c

${SRC}.o:${SRC}.c
	${GCC} -c ${SRC}.c


clean:
	rm ${SRC}.o
	rm ${MAN}.o
	rm ${OBJ}


install:
	./${OBJ}
