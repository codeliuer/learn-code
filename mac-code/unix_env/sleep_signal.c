#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>


int nums = 0;
	

static void do_func(int signo)
{
	sleep(4);

	printf("nums = %d, line = %d\n", nums, __LINE__);
}


int main(int argc, char *argv[])
{
	signal(SIGINT, do_func);

	for (;;)
	{
		printf("nums = %d\n", nums);

		pause();
	}

	return EXIT_SUCCESS;
}
