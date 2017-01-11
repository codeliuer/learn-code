#ifndef __API_H__
#define __API_H__


#define MAP_PROCESS_SHARED      (1)
#define MAP_THREAD_SHARED       (2)


extern void *mapaddr_init(size_t length, int tag);
extern int mapaddr_destroy(void *addr, size_t length);


#endif  //__API_H__
