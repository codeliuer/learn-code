#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


extern int errno;

int
main(int argc, char* argv[])
{
	//printf("%s\n", strerror(errno));
	errno = 1;
	perror(strerror(errno));
	//strerror(errno);

	return EXIT_SUCCESS;
}
