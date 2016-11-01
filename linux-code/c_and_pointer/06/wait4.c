#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/wait.h>
#include <sys/resource.h>


int
main(int argc, char * argv[])
{
    pid_t pid;
    struct rusage usage;

    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "fork failure\n");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        sleep(1);
        exit(EXIT_SUCCESS);
    } 

    wait4(pid, NULL, 0, &usage);

    printf("cpu user time = %lus: %lums\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    printf("cpu system time = %lus: %lums\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
    printf("maxinum resident set size = %lu\n", usage.ru_maxrss);
    printf("integral shared memory size = %lu\n", usage.ru_ixrss);
    printf("integral unshared data size = %lu\n", usage.ru_idrss);
    printf("integral unshared stack size = %lu\n", usage.ru_isrss);
    printf("page reclaims(soft page faults) = %lu\n", usage.ru_minflt);
    printf("page faults(hard page faults) = %lu\n", usage.ru_majflt);
    printf("swaps = %lu\n", usage.ru_nswap);
    printf("block input operations = %lu\n", usage.ru_inblock);
    printf("block output operations = %lu\n", usage.ru_oublock);
    printf("IPC messages send = %lu\n", usage.ru_msgsnd);
    printf("IPC messages received = %lu\n", usage.ru_msgrcv);
    printf("voluntary context switches = %lu\n", usage.ru_nvcsw);
    printf("involuntary context switches = %lu\n", usage.ru_nivcsw);

    return EXIT_SUCCESS;
}
