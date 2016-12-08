#
# display directory
#

SRC=dir.o main.o
OBJ=dir

CC=gcc

$(OBJ):$(SRC)
	$(CC) -g -o $@ $?

install:
	./$(OBJ)

.PHONY:clean
clean:
	-rm $(SRC) $(OBJ)

