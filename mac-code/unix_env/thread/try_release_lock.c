#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


#define infinite()		for (;;)


static pthread_mutex_t locka = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t lockb = PTHREAD_MUTEX_INITIALIZER;


static void *thread_func1(void *arg)
{
}

static void *thread_func2(void *arg)
{
	infinite()
	{
		if (pthread_mutex_lock(&locka) != 0)
		{
			fprintf(stderr, "pthread_mutex_lock a failure\n");
			return EXIT_FAILURE;
		}

		if (pthread_mutex_lock(&lockb) != 0)
		{
			fprintf(stderr, "pthread_mutex_lock b failure\n");
			return EXIT_FAILURE;
		}
	}
}

int main(int argc, char *argv[])
{
	int retcode = 0;
	pthread_t tid1;
	pthread_t tid2;

	if ((retcode = pthread_create(&tid1, NULL, thread_func1, NULL)) != 0)
	{
		fprintf(stderr, "pthread_create called failure\n");
		return EXIT_FAILURE;
	}

	if ((retcode = pthread_create(&tid2, NULL, thread_func2, NULL)) != 0)
	{
		fprintf(stderr, "pthread_create called failure\n");
		return EXIT_FAILURE;
	}

	if (pthread_join(tid1, NULL) != 0 && pthread_join(tid, NULL) != 0)
	{
		fprintf(stderr, "pthread_join failure\n");
		return EXIT_FAILURE;
	}

	sleep(1);

	return EXIT_SUCCESS;
}
