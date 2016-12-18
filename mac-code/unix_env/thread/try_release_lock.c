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

	return EXIT_SUCCESS;
}
