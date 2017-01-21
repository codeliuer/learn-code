/****************************************************************
 * task queue set and get
 ***************************************************************/

#ifndef __TASK_QUEUE_H__
#define __TASK_QUEUE_H__


#define TASK_ERRCODE_SUCCESS        (0)
#define TASK_ERRCODE_FAIL           (1)
#define TASK_ERRCODE_INITED         (2)
#define TASK_ERRCODE_ALLOC          (3)


typedef struct task
{
    void *(*task)(void *);
    void *arg;
    struct task *next;
} task_t;


extern int task_init(void);
extern int task_destroy(void);


#endif //__TASK_QUEUE_H__
