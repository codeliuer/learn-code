#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <signal.h>

#include <unistd.h>


static unsigned long num = 0;

static void
func(int signo)
{
	printf("%lu\n", num);
}

static void
register_signal(int signo)
{
	if (signal(SIGSEGV, func) == SIG_ERR)
	{
		fprintf(stderr, "signal register failure\n");
		return;
	}
}

int
main(int argc, char* argv[])
{
	if (num == 0)
	{
		register_signal(SIGSEGV);
		printf("register signal\n");
	}

	num++;
	kill(getpid(), SIGSEGV);
	main(argc, argv);

	return EXIT_SUCCESS;
}
