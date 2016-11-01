#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	DEBUG			(1)


int
main(int argc, char* argv[])
{
#if (DEBUG == 1)
	printf("if\n");
#else
	printf("else\n");
#endif	//DEBUG

	return EXIT_SUCCESS;
}
