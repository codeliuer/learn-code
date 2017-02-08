#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>
#include <sys/resource.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>


void daemonize(const char *cmd)
{
    pid_t pid;
    struct rlimit rlim = NULL;

    umask(0);

    if (getrlimit(RLIMIT_NOFILE, &rlim) < 0)
    {
        fprintf(stderr, "getrlimit failure\n");
        return ;
    }

    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "fork failure\n");
        return;
    }
    else if (pid > 0)
    {
        exit(EXIT_SUCCESS);
    }

    setsid();
}

int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
