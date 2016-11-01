#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <pthread.h>
#include <semaphore.h>


#define forever_true()          for(;;)

sem_t sem;

static void 
sem_test(void)
{
//    sem_init(&sem, 0, 1);

    sem_wait(&sem);
    printf("pthread id = %ld\n", pthread_self());
    sleep(3);
    printf("pthread id = %ld\n", pthread_self());
    sem_post(&sem);
}


static void *
func1(void* arg)
{
    printf("pthread id = %ld\n", pthread_self());

    sem_test();
}


static void *
func2(void* arg)
{
    printf("pthread id = %ld\n", pthread_self());

    sem_test();
}


int
main(int argc, char* argv[])
{
    pthread_t pthid;

    sem_init(&sem, 0, 1);
    pthread_create(&pthid, NULL, func1, NULL);
    pthread_create(&pthid, NULL, func2, NULL);
//    pthread_create(&pthid, NULL, func, NULL);

    forever_true();

    return EXIT_SUCCESS;
}
