#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char *argv[])
{
	int a[3][10], (*p)[3];

	p = a;

	printf("%p\n", p);

	return EXIT_SUCCESS;
}
