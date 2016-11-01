/*
** test mul thread signal question
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <unistd.h>
#include <sched.h>
#include <pthread.h>


#define COMMON				(0)
#define WAIT				(1)
#define RUN					(2)


#define forever_true()			for(;;)


static void *do_product(void *);
static void *do_wait(void *);
static void *do_over(void *);


struct 
{
	int				priority;
	void * (*pThreadfunc)(void *);
} action[] = 
	{
		{10, do_product},
		{50, do_wait},
		{90, do_over},
	};

static int ginfo = 0;


static void *
do_product(void *arg)
{
	ginfo = 1;

	printf("do product\n");

	pthread_exit(NULL);
}

static void *
do_wait(void *arg)
{
	while (ginfo == 0);

	printf("do wait\n");

	pthread_exit(NULL);
}

static void *
do_over(void *arg)
{
	while (ginfo == 1);

	printf("do over\n");

	pthread_exit(NULL);
}

static void
create_thread(int tag)
{
	pthread_t th;
	pthread_attr_t attr;
	struct sched_param param;

	pthread_attr_init(&attr);
	pthread_attr_setschedpolicy(&attr, SCHED_RR);
	param.sched_priority = action[tag].priority;
	pthread_attr_setschedparam(&attr, &param);

	pthread_create(&th, &attr, action[tag].pThreadfunc, NULL);
}

static void 
delay(void)
{
	usleep(1000000);
}

int
main(int argc, char* argv[])
{
	create_thread(COMMON);
	create_thread(WAIT);
	create_thread(RUN);

	delay();
//	forever_true();

	return EXIT_SUCCESS;
}
