#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


int
main(int argc, char* argv[])
{
	printf("FOPEN_MAX = %d\n", FOPEN_MAX);
	printf("FILENAME_MAX = %d\n", FILENAME_MAX);

	return EXIT_SUCCESS;
}
