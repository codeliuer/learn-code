#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>


static void do_func(int signo)
{
	printf("catch signal number %d\n", signo);
}


extern int errno;

int main(int argc, char *argv[])
{
	int ch;

	signal(SIGINT, do_func);

	errno = 0;
	printf("read = %ld\n", read(STDIN_FILENO, &ch, 1));
	printf("errno = %d\n", errno);

	return EXIT_SUCCESS;
}
