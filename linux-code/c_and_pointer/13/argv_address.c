#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
	int* p = malloc(10);

	printf("%p\n", *argv);
	printf("%p\n", *(argv+1));
	printf("%p\n", p);
//	printf("%p\n", *(argv+2));
//	printf("%p\n", *(argv+3));

	return EXIT_SUCCESS;
}
