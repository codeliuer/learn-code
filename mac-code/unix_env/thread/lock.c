#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


#define infinite()		for (;;)


static pthread_mutex_t locka;
static pthread_mutex_t lockb;

static void init_locka(void)
{
	pthread_mutex_init(&locka, NULL);
}

static void init_lockb(void)
{
	pthread_mutex_init(&lockb, NULL);
}

static void init_lock(void)
{
	init_locka();
	init_lockb();
}

static void *write_data(void *arg)
{
	pthread_mutex_lock(&locka);
	printf("write_data thread get locka\n");

	sleep(1);

	pthread_mutex_lock(&lockb);
	printf("write_data thread get lockb\n");

	sleep(2);

	pthread_mutex_unlock(&lockb);
	pthread_mutex_unlock(&locka);

	pthread_exit(NULL);
}

static void *read_data(void *arg)
{
	usleep(10000);

	while (pthread_mutex_trylock(&locka) != 0)
	{
		usleep(100000);

		printf("try to get lock\n");
	}
	printf("read_data thread get locka\n");

	sleep(1);

	pthread_mutex_lock(&lockb);
	printf("read_data thread get lockb\n");

	sleep(2);

	pthread_mutex_unlock(&lockb);
	pthread_mutex_unlock(&locka);

	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t tid1, tid2;

	init_lock();

	pthread_create(&tid1, NULL, write_data, NULL);
	pthread_create(&tid2, NULL, read_data, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	return EXIT_SUCCESS;
}
