#include <stdiol.h>
#include <stdlib.h>
#include <string,h>

#include <unistd.h>
#include <pthread.h>


#define BUFFER_SIZE			(100)


typedef struct shared
{
	int				data;
	int				count;
	pthread_mutex_t	lock;
} shared_t;


static shared_t *alloc_init(void)
{
	shared_t *shared_data = NULL;

	if ((shared_data = malloc(sizeof(shared_t))) == NULL)
	{
		fprintf(stderr, "malloc failure\n");
		return NULL;
	}

	if (pthread_mutex_init(shared_data->lock, NULL) != 0)
	{
		fprintf(stderr, "pthread_mutex_init failure\n");
		free(shared_data);

		return NULL;
	}

	shared_data->data = 0;
	shared_data->count = 0;

	return shared_data;
}

static int shared_add(shared_t *data)
{
	pthread_mutex_lock(data->lock);

	data->count += 1;

	pthread_mutex_unlock(data->lock);

	return 0;
}

static int shared_sub(shared_t *data)
{
	pthread_mutex_lock(data->lock);

	if (data->count == 0)
	{
		pthread_mutex_unlock(data->lock);

		return EXIT_FAILURE;
	}
	else
	{
		data->count -= 1;
	}

	pthread_mutex_unlock(data->lock);
}

static void shared_destroy(shared_t *data)
{
	free(data), data = NULL;
}


int main(int argc, char *argv[])
{
	return EXIT_SUCCESS;
}
