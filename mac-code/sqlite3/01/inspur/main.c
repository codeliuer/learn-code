#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
	char arr[] = "123456";
	const char* ptr = arr;
	char* tmp = (char *)ptr;
	
	*tmp = '2';
	*ptr = '2';	//error read-only variable

	return EXIT_SUCCESS;
}
