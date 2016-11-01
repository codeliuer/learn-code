#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <unistd.h>


extern int errno;


int
main(int argc, char *argv[])
{
	int value = nice(11);

	if (errno != 0)
	{
		perror("get nice failure: ");
		return EXIT_FAILURE;
	}

	printf("the priority of the process = %d\n", value);

	value = nice(-1);

	if (errno != 0)
	{
		perror("get nice failure: ");
		return EXIT_FAILURE;
	}

	printf("the priority of the process = %d\n", value);

	return EXIT_SUCCESS;
}
