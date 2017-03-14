#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

#include <aio.h>

#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/types.h>


#define UNUSED(x)           ((void)(x))


extern int errno;

static off_t offset = 0;

static void aio_dealwith(int signo, siginfo_t *info, void *arg)
{
    int nbytes = 0;
    struct aiocb *paiocb = (struct aiocb *)info->si_value.sival_ptr;

    UNUSED(signo), UNUSED(arg);

    errno = 0;
    if (aio_error(paiocb) == 0)
    {
        if ((nbytes = aio_return(paiocb)) == 0)
        {
            exit(EXIT_SUCCESS);
        }
        else if (nbytes > 0)
        {
            printf("%s", paiocb->aio_buf);
            offset += nbytes;
        }
    }
    else
    {
        printf("errno = %d\n", errno);
    }
}

static void register_signal(int signo)
{
    struct sigaction action = {0};

    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = aio_dealwith;

    if (sigaction(signo, &action, NULL) != 0)
    {
        fprintf(stderr, "sigaction failure\n");
        return ;
    }
}


int main(int argc, char *argv[])
{
    int fd = 0;
    struct aiocb aiocb = {0};

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./a.out filename1 filename2 ...\n");
        return EXIT_FAILURE;
    }

    register_signal(SIGIO);

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "open failure\n");
        return EXIT_FAILURE;
    }

    aiocb.aio_fildes = fd;
    aiocb.aio_buf = (volatile void *)malloc(BUFSIZ+1);
    aiocb.aio_nbytes = BUFSIZ;
    aiocb.aio_sigevent.sigev_notify = SIGEV_SIGNAL;
    aiocb.aio_sigevent.sigev_signo = SIGIO;
    aiocb.aio_sigevent.sigev_value.sival_ptr = &aiocb;

    memset((void *)aiocb.aio_buf, 0, BUFSIZ+1);
    aiocb.aio_offset = offset;

    aio_read(&aiocb);

    sleep(1);
    return EXIT_SUCCESS;
}
