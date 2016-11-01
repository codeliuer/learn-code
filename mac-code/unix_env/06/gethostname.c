#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <unistd.h>


int
main(int argc, char* argv[])
{
	int hostlen = sysconf(_SC_HOST_NAME_MAX);
	char* name = malloc(sizeof(*name) * hostlen);

	gethostname(name, sizeof(name));
	printf("%s\n", name);

	return EXIT_SUCCESS;
}
