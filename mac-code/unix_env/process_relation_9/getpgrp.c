#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>


int
main(int argc, char *argv[])
{
	pid_t pid;

	pid = getpgrp();
	printf("progress group id = %d\n", pid);

	printf("current progress id = %d\n", getpid());
	printf("current progress father id = %d\n", getppid());

	printf("call progress id = %d\n", getpgid(0));

	return EXIT_SUCCESS;
}
