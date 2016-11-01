#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
	char string[10] = {0};
	char* ptr = "1234567890";

	strcpy(string, ptr);

	printf("%s\n", string);

	return EXIT_SUCCESS;
}
