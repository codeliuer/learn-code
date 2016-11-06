#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


static void do_func(int signo)
{
	printf("catch signo = %d, pid = %d\n", signo, getpid());
	exit(EXIT_FAILURE);
}


int main(int argc, char *argv[])
{
	pid_t pid;

	if (signal(SIGTERM, do_func) == SIG_ERR)
	{
		fprintf(stderr, "do function register failure\n");
		return EXIT_SUCCESS;
	}

	if ((pid = fork()) < 0)
	{
		fprintf(stderr, "fork failure\n");
		return EXIT_SUCCESS;
	}
	else if (pid == 0)
	{
		printf("child process pid = %d\n", getpid());
		for (;;)
		{
			sleep(1);
		}
	}
	else
	{
		sleep(1);
		printf("father process quit pid = %d\n", getpid());
	}

	return EXIT_SUCCESS;
}
