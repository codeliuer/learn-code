#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


static pthread_mutex_t locka = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t lockb = PTHREAD_MUTEX_INITIALIZER;




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

	if (pthread_join(&tid1, NULL) == 0)

	return EXIT_SUCCESS;
}
