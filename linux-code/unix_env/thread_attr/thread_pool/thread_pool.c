#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <unistd.h>

#include "task_struct.h"
#include "task.h"


#define forever_true()      for (;;)


static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

static void *thread_task(void *arg)
{
    forever_true()
    {
        pthread_mutex_lock();
    }
}
