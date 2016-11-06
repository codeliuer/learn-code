#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


static void do_func(int signo)
{
	printf("father process pid = %d\n", getpid());
	printf("continue\n");
}

static void do_child(int signo)
{
	printf("child process pid = %d\n", getpid());
	printf("child continue\n");
}

int main(int argc, char *argv[])
{
	pid_t pid;

	if (signal(SIGTTOU, do_func) == SIG_ERR)
	{
		fprintf(stderr, "signal do function register failure\n");
		return EXIT_FAILURE;
	}

	if ((pid = fork()) < 0)
	{
		fprintf(stderr, "fork failure\n");
		return EXIT_SUCCESS;
	}
	else if (pid == 0)
	{
		if (signal(SIGTTOU, do_child) == SIG_ERR)
		{
			fprintf(stderr, "do_child fialure\n");
			exit(EXIT_FAILURE);
		}

		printf("child process id = %d\n", getpid());
		sleep(1);

		exit(EXIT_SUCCESS);
	}
	else
	{
		sleep(1);
		int data = 0;
		printf("data = %d\n", data);
	};

	sleep(2);

	return EXIT_SUCCESS;
}
