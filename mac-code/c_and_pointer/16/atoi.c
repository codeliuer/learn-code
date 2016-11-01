#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define	ALPHABET1				"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define	ALPHABET2				"0123456789abcdefghijklmnopqrstuvwxyz"


int
main(int argc, char* argv[])
{
	printf("%d\n", atoi("  3 3"));
	printf("%lu\n", sizeof(LONG_MAX));
	printf("%lu\n", sizeof(int));

	return EXIT_SUCCESS;
}
