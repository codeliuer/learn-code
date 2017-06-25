/*
 * process sync and thread sync
 */
#ifndef __SYNC_H__
#define __SYNC_H__


#define PUBLIC          // extern api


#include <unistd.h>


extern int TELL_WAIT(void);
extern int WAIT_PARENT(void);
extern int WAIT_CHILD(void);
extern int TELL_PARENT(pid_t pid);
extern int TELL_CHILD(pid_t pid);


#endif //__SYNC_H__
