#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


static int num = 0;

static void do_func(int signo)
{
	num++;
	printf("num = %d, signo = %d\n", num, signo);

	alarm(1);
}


int main(int argc, char *argv[])
{
	signal(SIGALRM, do_func);
	alarm(1);

	printf("pid = %d\n", getpid());

	for (;;);

	return EXIT_SUCCESS;
}
