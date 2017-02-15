/********************************************************
 *
 *
 *******************************************************/

#ifndef __PROCESS_SYNC_API_H__
#define __PROCESS_SYNC_API_H__

#include <unistd.h>


extern void TELL_WAIT(void);

extern void TELL_CHILD(pid_t pid);
extern void WAIT_CHILD(void);

extern void TELL_PARENT(pid_t pid);
extern void WAIT_PARENT(void);


#endif //__PROCESS_SYNC_API_H__
