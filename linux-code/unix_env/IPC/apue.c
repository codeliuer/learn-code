#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
    int n = 0;
    int fd[2];
    pid_t pid;
    char *pager, *argv0;
    char line[MAXLINE];
    FILE *fp;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./a.out filename\n");
        return EXIT_FAILURE;
    }

    return EXIT_FAILURE;
}
