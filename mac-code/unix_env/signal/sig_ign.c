#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


static void do_func(int signo)
{
	printf("signal number equal = %d\n", signo);
}


int main(int argc, char *argv[])
{
	if (signal(SIGINT, SIG_IGN) == SIG_IGN)
	{
		signal(SIGINT, do_func);
	}
	if (signal(SIGQUIT, SIG_IGN) == SIG_IGN)
	{
		signal(SIGQUIT, do_func);
	}

	for (;;)
	{
		pause();
	}

	return EXIT_SUCCESS;
}
