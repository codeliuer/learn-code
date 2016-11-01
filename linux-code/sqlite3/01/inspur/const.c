#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static const char* string1 = "123";
static const char* string2 = "123";
static const char* string3 = "123";
static const char* string4 = "123";


int 
main(int argc, char* argv[])
{
	const char* pArray[] = 
	{
		string1,		string2,
		string3,		string4,
	};

	return EXIT_SUCCESS;
}
