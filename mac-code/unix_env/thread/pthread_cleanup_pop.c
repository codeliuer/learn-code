#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <unistd.h>


static void clean_func(void *arg)
{
	printf("clean function\n");
}

static void *thread_func(void *arg)
{
	pthread_cleanup_push(clean_func, NULL);
	pthread_cleanup_pop(0);

	printf("thread function exec\n");

	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	int err = 0;
	pthread_t tid;

	err = pthread_create(&tid, NULL, thread_func, NULL);
	if (err != 0)
	{
		fprintf(stderr, "pthread_create function create function failure\n");
		return EXIT_FAILURE;
	}

	err = pthread_join(tid, NULL);
	if (err != 0)
	{
		fprintf(stderr, "pthread_join failure\n");
		return EXIT_SUCCESS;
	}

	return EXIT_SUCCESS;
}
