#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <termios.h>


int main(int argc, char *argv[])
{
	pid_t pid = tcgetpgrp(0);
	pid_t sid = tcgetsid(0);

	printf("pid = %d\n", pid);
	printf("current process id = %d\n", getpid());
	printf("session id = %d\n", tcgetsid(0));

	return EXIT_SUCCESS;
}
