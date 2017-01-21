#ifndef __TASK_STRUCT_H__
#define __TASK_STRUCT_H__


struct task_struct
{
    void *(* task)(void *);
    void *arg;
};


#endif //__TASK_STRUCT_H__
