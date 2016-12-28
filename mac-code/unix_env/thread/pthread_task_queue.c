#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


typedef unsigned int    u64_t;
typedef u64_t           job_id_t;

typedef struct job
{
    struct job          *j_next;
    struct job          *j_prev;
    job_id_t            id;   
} job_t;


typedef struct task 
{
    job_t               *t_head;
    job_t               *p_tail;
    pthread_rwlock_t    tid;
} task_t


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
