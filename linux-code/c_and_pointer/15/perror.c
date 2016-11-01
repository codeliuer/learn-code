#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


extern int errno;

int
main(int argc, char* argv[])
{
	errno = ERRNO;
	perror("name");

	return EXIT_SUCCESS;
}
