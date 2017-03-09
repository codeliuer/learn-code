#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <aio.h>
#include <errno.h>

#include <fcntl.h>


#define check_parameter(arg)                            \
    do {                                                \
        if (arg != 2)                                   \
        {                                               \
            fprintf(stderr, "parameter failure\n");     \
            exit(EXIT_FAILURE);                         \
        }                                               \
    } while (0)

int main(int argc, char *argv[])
{
    int fd = 0;
    int ret = 0;
    struct aiocb my_aiocb = {0};

    check_parameter(argc);

    fd = open(argv[argc-1], O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "open failure\n");
        return EXIT_FAILURE;
    }

    my_aiocb.aio_buf    = malloc(BUFSIZ+1); 
    my_aiocb.aio_fildes = fd;
    my_aiocb.aio_nbytes = BUFSIZ;
    my_aiocb.aio_offset = 0;
    
    ret = aio_read(&my_aiocb);
    if (ret < 0)
    {
        fprintf(stderr, "aio_read failure\n");
        return EXIT_FAILURE;
    }

    while (aio_error(&my_aiocb) == EINPROGRESS);

    if ((ret = aio_return(&my_aiocb)) > 0)
    {
        printf("%s", my_aiocb.aio_buf);
    }
    else
    {
        fprintf(stderr, "aio_return failure\n");
    }

    return EXIT_SUCCESS;
}
