#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


typedef unsigned int    u64_t;
typedef u64_t           job_id_t;

typedef void *(*work_t)(void *);

typedef struct job
{
    struct job          *j_next;
    struct job          *j_prev;
    job_id_t            j_id;   

    work_t              *j_work;
    void                *j_arg;

    void                *j_result;
} job_t;


typedef struct task 
{
    job_t               *t_head;
    job_t               *t_tail;
    pthread_rwlock_t    t_lock;
} task_t;


static void queue_init(task_t *head)
{
    head->t_head = NULL;
    head->t_tail = NULL;

    pthread_rwlock_init(&head->t_lock, NULL);
}


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
