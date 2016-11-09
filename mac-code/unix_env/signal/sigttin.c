#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#include <unistd.h>


static void do_func(int signo)
{
	printf("signo = %d\n", signo);
}


extern int errno;

int main(int argc, char *argv[])
{
	int ch;
	pid_t pid;

	if ((pid = fork()) < 0)
	{
		fprintf(stderr, "fork failure\n");
		return EXIT_FAILURE;
	}
	else if (pid == 0)
	{
		signal(SIGHUP, do_func);

		kill(getpid(), SIGTSTP);
		if (read(STDIN_FILENO, &ch, 1) < 0)
		{
			fprintf(stderr, "read error %d %d on controlling\n", errno, EIO);
			exit(EXIT_FAILURE);
		}
		printf("success\n");
	}
	else
	{
		sleep(1);
	}

	return EXIT_SUCCESS;
}
