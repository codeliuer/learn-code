#include <stdio.h>
#include <stdlib.h>


int
main(int argc, char *argv[])
{
	for (; *argv != NULL; argv++)
	{
		printf("%s\n", *argv);
	}

	return EXIT_SUCCESS;
}
