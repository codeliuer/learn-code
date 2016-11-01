#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char * agrv[])
{
	int arr[3][4][5] = {0};

	printf("%lu\n", sizeof(arr[3]));
	printf("%lu\n", sizeof(arr[3]+1));

	return EXIT_SUCCESS;
}
