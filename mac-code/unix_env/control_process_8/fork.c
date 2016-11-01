#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


static int glovar = 6;
static char buf[] = "a write to stdout\n";


int
main(int argc, char* argv[])
{
    int var = 0;
    pid_t pid;
#define BUF_TEST
#ifdef BUF_TEST
    static char buffer[BUFSIZ] = "";

    setvbuf(stdout, buffer, _IOFBF, sizeof(buffer));
#endif //BUF_TEST

    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
    {
        fprintf(stderr, "write failure\n");
        return EXIT_FAILURE;
    }
    printf("before fork\n");

    if ((pid = vfork()) < 0)
    {
        fprintf(stderr, "fork failure\n");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        glovar++;
        var++;

        _exit(EXIT_SUCCESS);
    }

    sleep(2);

    printf("pid = %ld, glovar = %d, var = %d\n", (long)getpid(), glovar, var);

    return EXIT_SUCCESS;
}
