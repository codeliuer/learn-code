#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


struct rwlock_t 
{
    pthread_mutex_t rdlock;
    int             count;
    pthread_mutex_t wrlock;
};


int my_rwlock_init(struct rwlock_t *rwlock)
{
    pthread_mutex_init(&rwlock->rdlock);
    rwlock->count = 0;
    pthread_mutex_init(&rwlock->wrlock);

    return EXIT_SUCCESS;
}

int my_rwlock_rdlock(struct rwlock_t *rwlock)
{
    if (pthread_mutex_trylock(&rwlock->rdlock))
    {
        pthread_mutex_lock(&rwlock->wrlock);
        rwlock->count += 1;
        pthread_mutex_unlock(&rwlock->wrlock);
    }
    else
    {
        rwlock->count += 1;
    }
    
    return EXIT_SUCCESS;
}

int my_rwlock_wrlock(struct rwlock_t *rwlock)
{
    if (pthread_mutex_trylock(&rwlock->rwlock))
    {
    }
    else
    {
    }

    return EXIT_SUCCESS;
}

int my_rwlock_unlock(struct rwlock_t *rwlock)
{
}

int my_rwlock_destroy(struct rwlock_t *rwlock)
{
}


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
