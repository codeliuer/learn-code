#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char *argv[])
{
	const char *str1 = "abc";
	const char *str2 = "abc";

	printf("%p, %p\n", str1, str2);

	return EXIT_SUCCESS;
}
