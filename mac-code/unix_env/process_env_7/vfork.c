#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>


int
main(int argc, char *argv[])
{
	if (vfork() == 0)
	{
		printf("son\n");
	}
	else
	{
		printf("parent\n");
	}

	return EXIT_SUCCESS;
}
