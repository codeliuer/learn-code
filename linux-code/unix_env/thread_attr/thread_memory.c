#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <unistd.h>


#define MAX_BLOCK           (10*1024*1024)

#define HEAD_LEN            (sizeof(struct block_info))


struct block_info
{
    size_t      total_size;
    struct block_info *next;
};


static pthread_key_t  process_key;
static pthread_once_t once = PTHREAD_ONCE_INIT;

static size_t align_size(size_t len)
{
}

void *make_space(size_t len)
{
    size_t align_len = align_size(len);
}

static void thread_free(void *arg)
{
    pthread_key_delete(process_key);

    struct block_info *tmp = NULL;

    for (tmp = ((struct block_info *)arg)->next; arg != NULL; arg = tmp)
    {
        free(arg);
        arg = NULL;
    }
}

static void bind_key(void)
{
    pthread_key_create(&process_key, thread_free);
}

void memory_init(void)
{
    void *ptr = NULL;
    struct block_info *info = NULL;

    pthread_once(&once, bind_key);
    ptr = pthread_getspecific(process_key);
    if (ptr == NULL)
    {
        ptr = malloc(MAX_BLOCK + HEAD_LEN);
        info = (struct block_info *)ptr;
        info->total_size = MAX_BLOCK;
        info->next = NULL;

        pthread_setspecific(process_key, ptr);
    }
}
