#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>

#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h>


#define N		(10)


static void 
do_signal(int signo)
{
	printf("signal catch thread id = %ld\n", pthread_self());

	printf("signal no = %d\n", signo);
}


static void *
thread_func(void *arg)
{
	printf("other thread id = %ld\n", pthread_self());

	usleep(500);

	raise(SIGSEGV);

	printf("continue\n");

	pthread_exit(NULL);
}

static void *
func(void *arg)
{
	printf("func thread id = %ld\n", pthread_self());

	usleep(1000);

	pthread_exit(NULL);
}

int
main(int argc, char *argv[])
{
	int i = 0;
	pthread_t t[N] = {0};
	pthread_t thid;

	printf("main thread id = %ld\n", pthread_self());

	if (signal(SIGSEGV, do_signal) == SIG_ERR)
	{
		fprintf(stderr, "signal register failure\n");
		return EXIT_FAILURE;
	}

	for (i = 0; i < N; i++)
	{
		pthread_create(&t[i], NULL, func, NULL);
	}

	pthread_create(&thid, NULL, thread_func, NULL);
//	pthread_join(thid, NULL);
	for (i = 0; i < N; i++)
	{
		pthread_create(&t[i], NULL, func, NULL);
	}

	sleep(1);

	return EXIT_SUCCESS;
}
