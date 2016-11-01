#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <unistd.h>
#include <pthread.h>


#define forever_true()			for(;;)


typedef struct work_list_t
{
	void					*(* task_process)(void *);
	void					*param;
	struct work_list_t		*next;
} work_list_t;


typedef struct thread_pool_t
{
	pthread_mutex_t			queue_lock;
	pthread_cond_t			queue_cond;
	work_list_t				*work_list;
#define THREAD_MAX			(100)
	pthread_t				thid[THREAD_MAX];
#define THREAD_POOL_ON		(0)
#define THREAD_POOL_OFF		(1)
	int						shutdown;
} thread_pool_t;


static thread_pool_t thread_pool = {0};

static void *
thread_func(void *arg)
{
	work_list_t *task;

//	printf("Enter thread number: %lu\n", pthread_self());

	forever_true()
	{
		pthread_mutex_lock(&thread_pool.queue_lock);
		while (thread_pool.work_list == NULL && thread_pool.shutdown == THREAD_POOL_ON)
		{
			pthread_cond_wait(&thread_pool.queue_cond, &thread_pool.queue_lock);
		}

		if (thread_pool.shutdown == THREAD_POOL_OFF)
		{
			pthread_mutex_unlock(&thread_pool.queue_lock);
//			printf("thread %d exit\n", pthread_self());
			pthread_exit(NULL);
		}

		task = thread_pool.work_list;
		thread_pool.work_list = thread_pool.work_list->next;

		pthread_mutex_unlock(&thread_pool.queue_lock);

		task->task_process(task->param);

		free(task);
		task = NULL;
	}

	pthread_exit(NULL);
}

static void
thread_pool_init(void)
{
	int i = 0;

	pthread_mutex_init(&thread_pool.queue_lock, NULL);
	pthread_cond_init(&thread_pool.queue_cond, NULL);
	thread_pool.work_list = NULL;

	for (i = 0; i < THREAD_MAX; i++)
	{
		pthread_create(&thread_pool.thid[i], NULL, thread_func, NULL);
	}
}

static void
thread_pool_destroy(void)
{
	int i = 0;
	work_list_t *tmp = NULL;

	if (thread_pool.shutdown == THREAD_POOL_OFF)
	{
		return;
	}
	thread_pool.shutdown = THREAD_POOL_OFF;

	pthread_cond_broadcast(&thread_pool.queue_cond);

	/* destroy wait queue */
	while ((tmp = thread_pool.work_list) != NULL)
	{
		thread_pool.work_list = thread_pool.work_list->next;

		free(tmp);
		tmp = NULL;
	}

	while (i < THREAD_MAX)
	{
		pthread_join(thread_pool.thid[i++], NULL);
	}

	pthread_cond_destroy(&thread_pool.queue_cond);
	pthread_mutex_destroy(&thread_pool.queue_lock);
}

static void
add_task(void *(* task)(void *), void *arg)
{
	work_list_t *node = NULL;
	work_list_t **pptmp = &thread_pool.work_list;

	node = (work_list_t *)malloc(sizeof(*node));
	assert(node != NULL);
	node->task_process = task;
	node->param = arg;

	pthread_mutex_lock(&thread_pool.queue_lock);

	while (*pptmp != NULL)
	{
		pptmp = &(*pptmp)->next;
	}
	*pptmp = node;

	pthread_mutex_unlock(&thread_pool.queue_lock);

	pthread_cond_signal(&thread_pool.queue_cond);
}

static void * 
func(void *arg)
{
	printf("thread id = %d\n", pthread_self());

	return NULL;
}

int
main(int argc, char* argv[])
{
	thread_pool_init();
	add_task(func, NULL);
	printf("%d second\n", sleep(1));
	thread_pool_destroy();

	return EXIT_SUCCESS;
}
