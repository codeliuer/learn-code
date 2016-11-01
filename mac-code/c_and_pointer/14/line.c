#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
#line 100 "test.txt"
	printf("%d, %s\n", __LINE__, __FILE__);

	return EXIT_SUCCESS;
}
