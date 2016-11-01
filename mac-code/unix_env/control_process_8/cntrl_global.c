#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


#define A               'A'
#define B               'B'
#define C               'C'


#define LOOP_MAX        (10)

#define array_num(arr)  (sizeof(arr)/sizeof(arr[0]))


#define forever_true()  for(;;)


typedef struct PARAM_t
{
    pthread_t       tid;
    int             equal;
    int             cntrl;
} PARAM_t;


typedef struct JUDGE_t
{
    pthread_mutex_t mutex;
    pthread_cond_t  cond;
    int             flag;
} JUDGE_t;


static JUDGE_t judge;


static void *
func(void *arg)
{
    int i = 0;
    PARAM_t *ptr = (PARAM_t *)arg;

    for (i = 0; i < LOOP_MAX; i++)
    {
        pthread_mutex_lock(&judge.mutex);
        while (judge.flag != ptr->equal)
        {
            pthread_cond_wait(&judge.cond, &judge.mutex);
        }

        printf("%c", ptr->equal);
        judge.flag = ptr->cntrl;
        pthread_mutex_unlock(&judge.mutex);

        pthread_cond_broadcast(&judge.cond);
    }

    pthread_exit(NULL);
}


static void
init(void)
{
    pthread_mutex_init(&judge.mutex, NULL);
    pthread_cond_init(&judge.cond, NULL);
    judge.flag = A;

    setvbuf(stdout, NULL, _IONBF, 0);
}


static void
uninit(void)
{
    ;
}


int
main(int argc, char *argv[])
{
    size_t i = 0;
    PARAM_t param[] = 
        {
            {0, A, B},
            {0, B, C},
            {0, C, A},
        };

    init();

    for (i = 0; i < array_num(param); i++)
    {
        pthread_create(&param[i].tid, NULL, func, &param[i]);
    }

    forever_true();

    uninit();

    return EXIT_SUCCESS;
}
