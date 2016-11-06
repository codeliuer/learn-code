#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


int
main(int argc, char *argv[])
{
	pid_t pid;

	if ( (pid = fork()) < 0 )
	{
		fprintf(stderr, "failure\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		sleep(1);

		setsid();
		printf("session id = %d\n", getsid(getpid()));

		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("father process quit\n");
		exit(EXIT_SUCCESS);
	}

	return EXIT_SUCCESS;
}
