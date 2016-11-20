#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>

#include <unistd.h>


static jmp_buf env = {0};

static void do_func(int signo)
{
	longjmp(env, 1);
}

static unsigned int sleep2(unsigned int seconds)
{
	if (signal(SIGALRM, do_func) == SIG_ERR)
	{
		return seconds;
	}

	printf("register success\n");

	if (setjmp(env) == 0)
	{
		alarm(seconds);
		sleep(5);
		pause();
	}
	printf("quit\n");

	return alarm(0);
}


int main(int argc, char *argv[])
{
	sleep2(10);

	return EXIT_SUCCESS;
}
