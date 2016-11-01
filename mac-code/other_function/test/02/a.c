#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char *argv[])
{
	long int a = 0x500;
	long int *p = &a;

	a =((long int)(*(&p)));
	a = (long int)(&(*p));

	if (a == (long int)p)
	{
		printf("equal\n");
	}
	else
	{
		printf("not equal\n");
	}

	return EXIT_SUCCESS;
}
