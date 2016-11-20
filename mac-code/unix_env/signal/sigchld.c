#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


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
		printf("child pid = %d\n", getpid());

		printf("over\n");

		exit(EXIT_SUCCESS);
	}
	else
	{
		for (;;);
	}

	return EXIT_SUCCESS;
}
