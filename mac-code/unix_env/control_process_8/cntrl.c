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


static int flag;


static void *
func(void *arg)
{
    int i = 0;
    PARAM_t *ptr = (PARAM_t *)arg;

    for (i = 0; i < LOOP_MAX; i++)
    {
        while (flag != ptr->equal);

        printf("%c", ptr->equal);
        flag = ptr->cntrl;
    }

    pthread_exit(NULL);
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

    flag = A;

    setvbuf(stdout, NULL, _IONBF, 0);

    for (i = 0; i < array_num(param); i++)
    {
        pthread_create(&param[i].tid, NULL, func, &param[i]);
    }

    forever_true();

    return EXIT_SUCCESS;
}
