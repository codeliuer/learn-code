#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

static pthread_mutex_t lock;

static void thread_once(void)
{
    pthread_mutexattr_t attr;

    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&lock, &attr);
    pthread_mutex_destroy(&attr);
}


char *get_env_r(const char *name, char *string, size_t size)
{
    int i = 0;
    char *local = NULL;
    size_t olen = 0;
    size_t len = strlen(name);

    pthread_once(PTHREAD_ONCE_INIT, thread_once);

    pthread_mutex_lock(&lock);
    for (i = 0; environ[i] != NULL; i++)
    {
        if (environ[i][len] == '=' 
            && strncmp(name, environ[i], len) == 0)
        {
            olen = strlen(&environ[i][len+1]);
            if (olen )
            pthread_mutex_unlock(&lock);
        }
    }
}


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
