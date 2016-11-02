#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


static void do_signal(int signo)
{
	printf("catch sig number = %d\n", signo);
}

static void ignore_signal(int signo)
{
	if (signal(signo, do_signal) == SIG_ERR)
	{
		fprintf(stderr, "signal regiter failure\n");
		exit(EXIT_FAILURE);
	}
}


int
main(int argc, char *argv[])
{
	ignore_signal(SIGINT);

	sleep(10);

	return EXIT_SUCCESS;
}
