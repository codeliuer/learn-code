#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <unistd.h>
#include <pthread.h>


typedef struct foo
{
    void            *data; //< data plug-in
    pthread_mutex_t lock; //< resource lock
    int             count; //< resource count
} foo_t;

static foo_t *resource_init(void *data)
{
    foo_t *foo = malloc(sizeof(*foo));
    assert(foo);

    if (pthread_mutex_init(&foo->lock, NULL) == 0) //< lock init success
    {
        foo->data = data;
        foo->count = 1;
    }
    else
    {
        free(foo), foo = NULL;
    }

    return foo;
}

static int resource_destroy(foo_t *foo)
{
    pthread_mutex_destroy(&foo->lock);

    free(foo), foo = NULL;

    return EXIT_SUCCESS;
}

static int resource_addcount(foo_t *foo)
{
    int retcode = EXIT_FAILURE;

    pthread_mutex_lock(&foo->lock);

    if (foo->count != 0)
    {
        foo->count += 1;
        retcode = EXIT_SUCCESS;
    }

    pthread_mutex_unlock(&foo->lock);

    return retcode;
}

static int resource_subcount(foo_t *foo)
{
    pthread_mutex_lock(&foo->lock);
    if (--foo->count == 0)
    {
        pthread_mutex_unlock(&foo->lock);
        resource_destroy(foo);
    }
    else
    {
        pthread_mutex_unlock(&foo->lock);
    }

    return EXIT_SUCCESS;
}


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
