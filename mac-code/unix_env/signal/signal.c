#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


static void do_func(int signo)
{
	printf("catch signal number = %d\n", signo);
}


int main(int argc, char *argv[])
{
	if (signal(SIGUSR1, do_func) == SIG_ERR)
	{
		fprintf(stderr, "deal with function\n");
		return EXIT_FAILURE;
	}

	if (signal(SIGUSR2, do_func) == SIG_ERR)
	{
		fprintf(stderr, "deal with function\n");
		return EXIT_FAILURE;
	}

	for (;;)
	{
		pause();
	}

	return EXIT_SUCCESS;
}
