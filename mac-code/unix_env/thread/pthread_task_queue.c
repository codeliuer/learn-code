#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>


typedef void *(*work_t)(void *);

typedef struct job
{
    struct job          *j_next;
    struct job          *j_prev;
    pthread_t           j_thid;

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

static int insert_task(task_t *queue, job_t *job)
{
    pthread_rwlock_wrlock(&queue->t_lock);

    job->j_next = queue->t_head;
    job->j_prev = NULL;
    if (queue->t_head != NULL)
    {
        queue->t_tail = job;
    }
    else
    {
        queue->t_head->j_prev = job;
    }
    queue->t_head = job;

    pthread_rwlock_unlock(&queue->t_lock);
}

static int append_task(task_t *queue, job_t *job)
{
    pthread_rwlock_wrlock(&queue->t_lock);

    job->j_prev = queue->t_tail;
    job->j_next = NULL;
    if (queue->t_tail != NULL)
    {
        queue->t_tail->j_next = job;
    }
    else
    {
        queue->t_head = job;
    }
    queue->t_tail = job;

    pthread_rwlock_unlock(&queue->t_lock);
}

static int remove_task(task_t *queue, job_t *job)
{
    pthread_rwlock_wrlock(&queue->t_lock);

    if (queue->t_head == job)
    {
        queue->t_head = job->j_next;
        if (queue->t_tail == job)
        {
            queue->t_tail = NULL;
        }
        else
        {
            job->j_next->j_prev = job->j_prev;
        }
    }
    else if (queue->t_tail == job)
    {
        queue->t_tail = job->j_prev;
        job->j_prev->j_next = job->j_next;
    }
    else
    {
        job->j_next->j_prev = job->j_prev;
        job->j_prev->j_next = job->j_next;
    }

    pthread_rwlock_unlock(&queue->t_lock);

    return 0;
}

static job_t *find_task(task_t *queue, pthread_t id)
{
    job_t *job_head = NULL;

    pthread_rwlock_rdlock(&queue->t_lock);

    for (job_head = queue->t_head; job_head != NULL; job_head = job_head->j_next)
    {
        if (pthread_equal(job_head->j_thid, id))
        {
            break;
        }
    }

    pthread_rwlock_unlock(&queue->t_lock);

    return job_head;
}


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
