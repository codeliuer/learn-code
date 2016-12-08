#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>

#include <unistd.h>


#define true			(1)

static void do_func(int signo)
{
	sigset_t set;

	printf("enter catch signal function\n");
	if (sigprocmask(SIG_BLOCK, NULL, &set) < 0)
	{
		fprintf(stderr, "signal failure\n");
		return;
	}

	if (sigismember(&set, SIGQUIT))
	{
		printf("SIGQUIT在阻塞队列中\n");
	}
	else
	{
		printf("SIGQUIT不在阻塞队列中\n");
	}

	if (sigismember(&set, SIGUSR1))
	{
		printf("sigusr1 is block signal\n");
	}
	printf("quit signal function\n");
}

int main(int argc, char *argv[])
{
	sigset_t oset, nset;
	sigset_t blockset;
	sigset_t oldblock;

	signal(SIGINT, do_func);

	sigemptyset(&nset);
	sigaddset(&nset, SIGINT);
	sigaddset(&nset, SIGQUIT);

	sigemptyset(&blockset);
	sigaddset(&blockset, SIGUSR1);

	if (sigprocmask(SIG_BLOCK, &nset, &oset) < 0)
	{
		fprintf(stderr, "sigprocmask failure\n");
		return EXIT_FAILURE;
	}

	printf("block signal SIGINT\n");

	sigsuspend(&blockset);

	if (sigprocmask(SIG_BLOCK, NULL, &oldblock) < 0)
	{
		fprintf(stderr, "signal sigprocmask\n");
		return EXIT_FAILURE;
	}
	if (sigismember(&oldblock, SIGQUIT))
	{
		printf("SIGQUIT还在阻塞队列中\n");
	}
	else
	{
		printf("SIGQUIT不在阻塞队列中了\n");
	}

	if (sigprocmask(SIG_UNBLOCK, &nset, &oset) < 0)
	{
		fprintf(stderr, "sig_unblock failure\n");
		return EXIT_FAILURE;
	}

	while (true);

	return EXIT_SUCCESS;
}
