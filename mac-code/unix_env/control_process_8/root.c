#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>


int
main(int argc, char *argv[])
{
	int fd;
	char buffer[BUFSIZ] = "write success";

	fd = open("test", O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "failure\n");
	}

	printf("%zd\n", write(fd, buffer, strlen(buffer)));

	close(fd);

	return EXIT_SUCCESS;
}
