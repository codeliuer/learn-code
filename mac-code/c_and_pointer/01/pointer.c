#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef void (* func)(void);


int
main(int argc, char *argv[])
{
	int arr[] = {1, 2, 3, 4,};

	int *ptr = arr;

	printf("%p\n", ptr);
	*(char *)ptr++;
	printf("%p\n", ptr);
	printf("%p\n", sizeof(func));
	printf("%p\n", sizeof(int *));

	return EXIT_SUCCESS;
}
