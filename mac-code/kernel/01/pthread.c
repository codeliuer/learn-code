/*
 * Test Linux real-time process priority and 
 * the priority of the norma; process
 *
 ************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sched.h>
#include <pthread.h>


#define forever_true()          for(;;)


typedef struct RANGE_t
{
    int         min;    //process priority min
    int         max;    //process priority max
} RANGE_t;


typedef struct PTHREAD_INFO_t
{
    int         priority;
    int         policy;
    void* (*fpCallback)(void*);
    void*       cbparam;
} PTHREAD_INFO_t;


static void
delay(void)
{
    int i = 0;
#define MAX_LOOP            (1000000000)
    for (i = 0; i < MAX_LOOP; i++)
    {
        ;
    }
}

static void 
get_priority_range(RANGE_t* p)
{
    p->min = sched_get_priority_min(SCHED_RR);
    p->max = sched_get_priority_max(SCHED_RR);
}


static void*
callback1(void* arg)
{
    forever_true()
    {
        delay();
        printf("%s  %ld\n", __func__, (long)arg);
    }

    return NULL;
}

static void*
callback2(void* arg)
{
    forever_true()
    {
        delay();
//        printf("%s  %ld\n", __func__, (long)arg);
    }

    return NULL;
}

static void*
callback3(void* arg)
{
    forever_true()
    {
        delay();
        printf("%s  %ld\n", __func__, (long)arg);
    }

    return NULL;
}

static void 
create(PTHREAD_INFO_t* pinfo)
{
    pthread_t thid;
    pthread_attr_t attr;
    struct sched_param sched;

    pthread_attr_init(&attr);
    pthread_attr_setschedpolicy(&attr, pinfo->policy);
    sched.sched_priority = pinfo->priority;
    pthread_attr_setschedparam(&attr, &sched);

    pthread_create(&thid, &attr, pinfo->fpCallback, pinfo->cbparam);
}

static void 
init(int range, int policy, void*(*cb)(void*), void*param)
{
    PTHREAD_INFO_t info;

    info.priority = range;
    info.policy = policy;
    info.fpCallback = cb;
    info.cbparam = param;
    create(&info);
}

int
main(int argc, char* argv[])
{
    int i = 0;
    RANGE_t range = {0};

    printf("pid = %d\n", getpid());

    get_priority_range(&range);

//    for (i = range.min; i <= range.max; i++)
//    {
        init(0, SCHED_RR, callback2, (void *)((long)0));
        init(39, SCHED_RR, callback2, (void *)((long)39));
        init(99, SCHED_RR, callback2, (void *)((long)99));
        init(69, SCHED_RR, callback2, (void *)((long)69));
//    }
    init(0, SCHED_OTHER, callback3, (void *)((long)0));

    forever_true();

    return EXIT_SUCCESS;
}
