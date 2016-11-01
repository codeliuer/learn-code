#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>


int
main(int argc, char *argv[])
{
	pid_t pid;

	if ((pid = fork()) < 0)
	{
		fprintf(stderr, "fork failure\n");
		return EXIT_SUCCESS;
	}
	else if (pid == 0)
	{
		if (execl("/Users/weiliu/learn-code/unix_env/control_process_8/echo.sh",
					"echo.sh", "arg1", "arg2", (char *)0) < 0)
		{
			perror("execl failure");
		}

		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}
