#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int
main(int argc, char* argv[])
{
	struct stat st;

	if (lstat("stat.c", &st) != 0)
	{
		fprintf(stderr, "error\n");
		return EXIT_FAILURE;
	}
	printf("file size = %lld\n", st.st_size);

	return EXIT_SUCCESS;
}
