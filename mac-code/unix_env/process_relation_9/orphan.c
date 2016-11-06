#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>


static void do_ttin(int signo)
{
	printf("signo = %d\n", signo);
}

extern int errno;

int main(int argc, char *argv[])
{
	pid_t pid;

	if ((pid = fork()) < 0)
	{
		fprintf(stderr, "fork failure\n");
		return EXIT_SUCCESS;
	}
	else if (pid == 0)
	{
		int c = 0;

		if (signal(SIGTTIN, do_ttin) == SIG_ERR)
		{
			perror("register signal failure:");
			exit(EXIT_FAILURE);
		}

		errno = 0;
		sleep(2);
		
		if (read(0, &c, 1) <= 0)
		{
			fprintf(stderr, "errno = %d\n", errno);
			perror("read failure\n");
			exit(EXIT_FAILURE);
		}

		exit(EXIT_SUCCESS);
	}
	else
	{
	}

	return EXIT_SUCCESS;
}
