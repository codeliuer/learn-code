#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <pthread.h>
#include <unistd.h>


#define N           (29)

#define hash(n)     ((n) % N)


struct foo *queue[N];

static pthread_mutex_t global_lock = PTHREAD_MUTEX_INITIALIZER;

struct foo 
{
    int                 f_count;
    void                *f_data;
    pthread_mutex_t     f_lock;
    struct foo          *f_next;
};

static int resource_queue_init(int id)
{
    int index = hash(id);
    struct foo *foo = malloc(sizeof(*foo));
    assert(foo);

    foo->f_count = 1;
    foo->f_data = NULL;
    pthread_mutex_init(&foo->f_lock, NULL);
    foo->f_next = NULL;

    pthread_mutex_lock(&global_lock);

    foo->f_next = queue[index];
    queue[index] = foo;

    pthread_mutex_lock(&foo->f_lock);
    pthread_mutex_unlock(&global_lock);
    foo->f_data = malloc(BUFSIZ);
    pthread_mutex_unlock(&foo->f_lock);

    return EXIT_SUCCESS;
}

static int resource_addcount(struct foo *foo)
{
    int retcode = EXIT_FAILURE;

    pthread_mutex_lock(&foo->f_lock);

    if (foo->f_count != 0)
    {
        foo->f_count += 1;
        retcode = EXIT_SUCCESS;
    }

    pthread_mutex_unlock(&foo->f_lock);

    return retcode;
}

static int resource_subcount(struct foo *foo)
{
    struct foo *tmp = NULL;

    pthread_mutex_lock(&foo->f_lock);

    if (--foo->count == 0)
    {
        pthread_mutex_unlock(&foo->f_lock);

        pthread_mutex_lock(&global_lock);
        pthread_mutex_lock(&foo->f_lock);

        if (foo->count != 0)
        {
            pthread_mutex_unlock(&foo->f_lock);
            pthread_mutex_unlock(&global_lock);
        }

        for (tmp = queue[0]; tmp != NULL; tmp = tmp->f_next)
        {
        }

        pthread_mutex_unlock(&foo->f_lock);
        pthread_mutex_unlock(&global_lock);
    }
    else
    {
        pthread_mutex_unlock(&foo->f_lock);
    }

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
