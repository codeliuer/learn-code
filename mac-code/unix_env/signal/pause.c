#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#include <unistd.h>


extern int errno;

static void do_func(int signo)
{
	int olderr = errno;
	
	printf("catch signal = %d\n", signo);

	errno = olderr;
}

int main(int argc, char *argv[])
{
	errno = 0;

	signal(SIGINT, do_func);

	printf("pause function return value = %d, errno = %d, EINTR = %d\n",
			pause(), errno, EINTR);

	return EXIT_SUCCESS;
}
