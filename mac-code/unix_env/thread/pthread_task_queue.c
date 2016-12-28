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

static job_id_t global_thread_id = 0;

static int insert_task(task_t *queue, job_t *job)
{
    pthread_rwlock_wrlock(&queue->t_lock);

    job->j_next = queue->t_head;
    job->j_prev = NULL;

    j_id = ++global_thread_id;

    pthread_rwlock_unlock(&queue->t_lock);
}

static int append_task(task_t *queue, job_t *job)
{
}

static int remove_task(task_t *queue, job_t *job)
{
}

static int find_task(task_t *queue, job_t *job)
{
}


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
