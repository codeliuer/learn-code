#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>


int 
main(int argc, char *argv[])
{
	printf("euid = %d, uid = %d\n", geteuid(), getuid());

	return EXIT_SUCCESS;
}
