#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>
#include <fcntl.h>

#include <syslog.h>


int main(int argc, char *argv[])
{   
    int i = 0;
    pid_t pid;
    struct sigaction sig;
    struct rlimit lim;
    int fd0 = 0, fd1 = 0, fd2 = 0;

    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "fork failure\n");
        return EXIT_FAILURE;    
    }
    else if (pid != 0)
    {
        exit(EXIT_SUCCESS);
    }

    setsid();

    sig.sa_handler = SIG_IGN;
    sigemptyset(&sig.sa_mask);
    sig.sa_flags = 0;

    sigaction(SIGHUP, &sig, NULL);

    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "the second fork failure\n");
        return EXIT_FAILURE;
    }
    else if (pid != 0)
    {
        exit(EXIT_SUCCESS);
    }

    umask(0);
    chdir("/");

    /* close all file descriptor */
    getrlimit(RLIMIT_NOFILE, &lim);

    for (i = 0; i < lim.rlim_cur; i++)
    {
        close(i);
    }

    fd0 = open("/dev/null", O_RDWR);
    fd1 = dup(fd0);
    fd2 = dup(fd0);

    openlog(cmd, );

    return EXIT_SUCCESS;
}
