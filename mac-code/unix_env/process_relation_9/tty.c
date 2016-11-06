#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>


int main(int argc, char *argv[])
{
	pid_t pid;

	if ((pid = fork()) < 0)
	{
		fprintf(stderr, "fork failure\n");
		return EXIT_FAILURE;
	}
	else if (pid == 0)
	{
		setsid();

		printf("pid = %d\n", getpid());

		int fd = open("/dev/tty", O_RDWR);
		if (fd < 0)
		{
			perror("open /dev/tty:");
			exit(EXIT_FAILURE);
		}

		int ret = ioctl(fd, TIOCSCTTY, NULL);
		if (ret < 0)
		{
			fprintf(stderr, "ioctl failure\n");
			return EXIT_FAILURE;
		}

		printf("pid = %d\n", getpid());

		for (;;);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}

	return EXIT_SUCCESS;
}
