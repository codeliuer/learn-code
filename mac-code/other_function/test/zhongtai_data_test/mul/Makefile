# mul

SRC=mul.o main.o
MAN=main
OBJ=test
CC=gcc


$(OBJ):${SRC}
	${CC} -o $(OBJ) $?

#main.o:main.c
#	${GCC} -c main.c

#mul.o:mul.c
#	${GCC} -c mul.c


.PHONY:clean
clean:
	-rm $(SRC) $(OBJ)

install:
	./${OBJ}
