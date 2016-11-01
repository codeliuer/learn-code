/*
** test void byte
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char * argv[])
{
	void *ptr = NULL;

	printf("%p\n", ptr+1);

	return EXIT_SUCCESS;
}
