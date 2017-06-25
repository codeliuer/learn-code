/*
 * process sync and thread sync
 */
#ifndef __SYNC_H__
#define __SYNC_H__


#define PUBLIC          // extern api


#include <unistd.h>


extern void TELL_WAIT(void);
extern void WAIT_PARENT(void);
extern void WAIT_CHILD(void);
extern void TELL_PARENT(pid_t pid);
extern void TELL_CHILD(pid_t pid);


#endif //__SYNC_H__
