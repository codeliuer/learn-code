#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	NAME			(100)

int
main(int argc, char* argv[])
{
	printf("%s %s\n", __DATE__, __TIME__);

	printf("%d\n", NAME);

	return EXIT_SUCCESS;
}
