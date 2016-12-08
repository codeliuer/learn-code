# compiler src file and delete intermediate files

CC=gcc
CFLAGS=-o3 -std=c99 \
    -Wall -Wextra -Wundef -Wfloat-equal -Wpointer-arith -Wcast-align \
    -Wstrict-prototypes -Wno-missing-field-initializers -Warray-bounds \
    -pedantic -fstrict-aliasing -g
LINKS=
INCLUDES=-I.

LIB_OBJS=
LIB_OBJS+=src.o
LIB_OBJS+=main.o

SRC_FILES=
SRC_FILES+=src.c
SRC_FILES+=main.c

EXEC=postfix

all: $(EXEC)
	@echo "execution begin---->"

$(EXEC): $(LIB_OBJS)
	@$(CC) $(CFLAGS) -o $@ $(LIB_OBJS) $(INCLUDES) $(LINKS)

$(LIB_OBJS): %.o: %.c
	@echo "cc: $<" 
	@$(CC) $(CFLAGS) -c $< $(INCLUDES) $(LINKS) -o $@ 

clean:
	find . -type f -name '*.o' -delete 
	rm -rf $(EXEC)

install:
	./$(EXEC)
