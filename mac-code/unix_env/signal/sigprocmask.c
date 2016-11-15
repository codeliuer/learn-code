#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


#define FLAG		(1)


static sigset_t set;

static void block(int signo)
{
	static int flag = 0;

	if (flag != FLAG)
	{
		sigemptyset(&set);
		flag = FLAG;
	}
	sigaddset(&set, signo);
}

static void clear(int signo)
{
	sigdelset(&set, signo);
}

static void do_func(int signo)
{
	printf("signo = %d\n", signo);
}

int main(int argc, char *argv[])
{
	sigset_t oset;

	block(SIGINT);
	block(SIGQUIT);
	sigprocmask(SIG_SETMASK, &set, &oset);
//	block(SIGQUIT);
	
	signal(SIGINT, do_func);

	sleep(3);
	clear(SIGINT);
	clear(SIGQUIT);
	sigprocmask(SIG_SETMASK, &set, &oset);
	printf("sleep = %d\n", sleep(2));

	return EXIT_SUCCESS;
}
