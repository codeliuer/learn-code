#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


static void do_func(int signo)
{
	static int raise_flag = 0;

	if (raise_flag != 2)
	{
		printf("this %dth send signal\n", raise_flag);
	
		raise(signo);
		raise_flag += 1;
	}

	printf("catch signal signo = %d\n", signo);
}

int main(int argc, char *argv[])
{
	if (signal(SIGINT, do_func) < 0)
	{
		fprintf(stderr, "signal register failure\n");
		return EXIT_SUCCESS;
	}

	raise(SIGINT);

	alarm(10);
	for (;;)
	{
		pause();
	}
	return EXIT_SUCCESS;
}
