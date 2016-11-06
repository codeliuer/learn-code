#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


#define forever()		for (;;)


int main(int argc, char *argv[])
{
	pid_t pid;

	if ((pid = fork()) < 0)
	{
		fprintf(stderr, "fork failure\n");
		return EXIT_FAILURE;
	}
	else
	{
		sleep(1);	// make true the father process quit

		if ((pid = fork()) < 0)
		{
			fprintf(stderr, "fork failure\n");
			return EXIT_FAILURE;
		}
		else if (pid == 0)
		{
			setsid();

			printf("pid = %d\n", getpid());
			forever();

			exit(EXIT_SUCCESS);
		}
		else
		{
			for (;;)
			{
				pid_t opid = fork();
				if (opid < 0)
				{
					fprintf(stderr, "failure\n");
					exit(EXIT_FAILURE);
				}
				else if (opid == 0)
				{
					if  (opid == pid)
					{
						printf("catch pid = %d\n", getpid());
						exit(EXIT_FAILURE);
					}
					else
					{
						exit(EXIT_FAILURE);
					}
				}
			}
		}
	}

	return EXIT_SUCCESS;
}
