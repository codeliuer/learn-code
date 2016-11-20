#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#include <unistd.h>


extern int errno;


int main(int argc, char *argv[])
{
	pid_t pid;

	signal(SIGCHLD, SIG_IGN);

	if ((pid = fork()) < 0)
	{
		fprintf(stderr, "fork failure\n");
		return EXIT_FAILURE;
	}
	else if (pid == 0)
	{
		sleep(2);
		printf("pid = %d over\n", getpid());

		exit(EXIT_SUCCESS);
	}
	else
	{
		if ((pid = fork()) < 0)
		{
			fprintf(stderr, "fork failure\n");
			return EXIT_SUCCESS;
		}
		else if (pid == 0)
		{
			sleep(4);
			printf("pid = %d over\n", getpid());

			exit(EXIT_SUCCESS);
		}
	}

	errno = 0;
	printf("wait = %d\n", wait(NULL));
	printf("errno = %d\n", errno);
	printf("ECHILD = %d\n", ECHILD);

	return EXIT_SUCCESS;
}
