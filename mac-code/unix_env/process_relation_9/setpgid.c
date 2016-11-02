#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <unistd.h>


int main(int argc, char *argv[])
{
	pid_t pid;

	printf("current progress id = %d\n", getpid());
	printf("current progress group id = %d\n", getpgrp());

	if ((pid = fork()) < 0)
	{
		fprintf(stderr, "fork failure\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		printf("the first1 child progress id = %d\n", getpid());
		printf("the first1 child progress group id = %d\n", getpgrp());

		if ((pid = fork()) < 0)
		{
			fprintf(stderr, "fork failure\n");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			printf("the second1 child progress id = %d\n", getpid());
			printf("the second1 child progress group id = %d\n", getpgrp());

			sleep(2);

			printf("the second2 child progress id = %d\n", getpid());
			printf("the second2 child progress group id = %d\n", getpgrp());

			exit(EXIT_SUCCESS);
		}
		else
		{
			sleep(1);

			setpgid(getpid(), getpid());

			printf("the first2 child progress id = %d\n", getpid());
			printf("the first2 child progress group id = %d\n", getpgrp());
		}

		exit(EXIT_SUCCESS);
	}
	else
	{
		sleep(5);
	}

	return EXIT_SUCCESS;
}
