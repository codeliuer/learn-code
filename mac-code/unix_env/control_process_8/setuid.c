#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


int
main(int argc, char *argv[])
{
	printf("uid = %d\n", getuid());
	printf("euid = %d\n", geteuid());
	printf("setuid: %d\n", setuid(0));
	printf("euid = %d\n", geteuid());

	return EXIT_SUCCESS;
}
