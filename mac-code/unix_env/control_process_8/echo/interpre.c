#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


int
main(int argc, char *argv[])
{
	int ret = 0;
	pid_t pid;

	if ((pid = fork()) < 0)
	{
		fprintf(stderr, "fork failure\n");
		return EXIT_FAILURE;
	}
	else if (pid == 0)
	{
		ret = execl("/Users/weiliu/learn-code/unix_env/control_process_8/test", "test", "arg1", "arg2", (char *)0);
		if (ret != 0)
		{
			perror("execl failure");
		}

		return EXIT_SUCCESS;
	}

	waitpid(pid, NULL, 0);

	return EXIT_SUCCESS;
}
