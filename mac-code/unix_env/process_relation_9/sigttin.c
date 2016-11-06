#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


static void ttin_do_func(int signo)
{
	printf("catch signal number = %d\n", signo);

	sleep(2);
}


int main(int argc, char *argv[])
{
	if (signal(SIGTTIN, ttin_do_func) == SIG_ERR)
	{
		fprintf(stderr, "sigttin failure\n");
		return EXIT_SUCCESS;
	}

	int data = 0;
	scanf("%d", &data);

	printf("%d\n", sleep(10));
//	raise(SIGTTIN);

	return EXIT_SUCCESS;
}
