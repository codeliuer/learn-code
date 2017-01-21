#ifndef __TASK_STRUCT_H__
#define __TASK_STRUCT_H__


#include <pthread.h>


struct task_struct
{
    void *(* task)(void *);
    void *arg;
};


extern pthread_mutex_t lock;
extern pthread_cond_t cond;


#endif //__TASK_STRUCT_H__
