#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <pthread.h>


#define infinite()		for (;;)


static pthread_mutex_t locka = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t lockb = PTHREAD_MUTEX_INITIALIZER;


static void *thread_func1(void *arg)
{
	infinite()
	{
		pthread_mutex_lock(&lockb);

		printf("thread_func1 lock b get success\n");

		if (pthread_mutex_trylock(&locka) != 0)
		{
			if (errno == EBUSY)
			{
				printf("lock a busy\n");
				pthread_mutex_lock(&lockb);

				continue;
			}
		}

		printf("thread_func1 all lock get success\n");

		break;
	}

	pthread_exit(NULL);
}

static void *thread_func2(void *arg)
{
	infinite()
	{
		pthread_mutex_lock(&locka);

		printf("thread_func2 lock a get success\n");

		if (pthread_mutex_trylock(&lockb) != 0)
		{
			if (errno == EBUSY)
			{
				printf("lock b busy\n");
				pthread_mutex_lock(&locka);

				continue;
			}
		}

		printf("thread_func2 all lock get success\n");

		break;
	}

	pthread_exit(NULL);
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

	if (pthread_join(tid1, NULL) != 0 && pthread_join(tid2, NULL) != 0)
	{
		fprintf(stderr, "pthread_join failure\n");
		return EXIT_FAILURE;
	}

	sleep(1);

	return EXIT_SUCCESS;
}
