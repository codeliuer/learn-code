#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[])
{
    // interval time
    struct timespec rem = {0, 0};
    struct timespec spec = {10, 0};

    int ret = clock_nanosleep(CLOCK_REALTIME, 0, &spec, NULL);
    if (ret < 0)
    {
        fprintf(stderr, "clock_nanosleep failure\n");
        return EXIT_FAILURE;
    }

    printf("sleep over\n");

    return EXIT_SUCCESS;
}
