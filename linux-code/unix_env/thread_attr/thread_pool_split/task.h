/******************************************************
 * thread task
 ******************************************************/

#ifndef __TASK_H__
#define __TASK_H__


extern int task_init(void);
extern int task_destroy(void);

extern int task_insert(void *);
extern int task_append(void *);
extern void *task_remove(void);


#endif //__TASK_H__
