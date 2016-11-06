#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/prctl.h>


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
		pr_ctl(PR_SET_PDEATHSIG, SIGHUP);

		while (1)
		{
			printf("circle\n");
			sleep(1);
		}
	}
	else
	{
		sleep(5);
	}

	return EXIT_SUCCESS;
}
