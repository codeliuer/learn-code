#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#include <unistd.h>


static void do_func(int signo);


int main(int argc, char *argv[])
{
	pid_t pid;

	if (signal(SIGCHLD, do_func) == SIG_ERR)
	{
		fprintf(stderr, "signal reigster failure\n");
	}

	if ((pid = fork()) < 0)
	{
		fprintf(stderr, "signal error\n");
		return EXIT_FAILURE;
	}
	else if (pid == 0)
	{
		sleep(2);
		_exit(EXIT_SUCCESS);
	}

	pause();

	return EXIT_SUCCESS;
}


static void do_func(int signo)
{
	pid_t pid;
	int status;

	printf("SIGCHLD received\n");

	if (signal(SIGCHLD, do_func) == SIG_ERR)
	{
		fprintf(stderr, "signal reigster failure\n");
	}

	if ((pid = wait(&status)) < 0)
	{
		perror("wait error");
	}
	printf("pid = %d\n", pid);
}
