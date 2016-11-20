#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>

static sigset_t set;

static void do_func(int signo)
{
	printf("signo = %d\n", signo);
}

static void block_signal(int signo)
{
	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGQUIT);

	sigprocmask(SIG_SETMASK, &set, NULL);
}

static void clear_signal(int signo)
{
	sigdelset(&set, SIGINT);
	sigdelset(&set, SIGQUIT);

	sigprocmask(SIG_SETMASK, &set, NULL);
}

int main(int argc, char *argv[])
{
//	signal(SIGINT, do_func);
//	signal(SIGQUIT, do_func);

//	block_signal(SIGINT);
//	block_signal(SIGQUIT);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);

	raise(SIGINT);
	raise(SIGINT);
	raise(SIGQUIT);
	raise(SIGQUIT);

	sleep(1);
	signal(SIGINT, do_func);
	signal(SIGQUIT, do_func);
//	clear_signal(SIGINT);
//	clear_signal(SIGQUIT);

	sleep(3);

	return EXIT_SUCCESS;
}
