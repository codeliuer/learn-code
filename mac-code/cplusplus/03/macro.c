#include <stdio.h>
#include <stdlib.h>


typedef struct dummy
{
	void *p;
	unsigned char slot;
} dummy_t;

#define OFFSET(type, member)			\
	(((size_t)&((type *)0)->member))

int main(int argc, char *argv[])
{
	printf("%lu\n", OFFSET(dummy_t, slot));

	return EXIT_SUCCESS;
}
