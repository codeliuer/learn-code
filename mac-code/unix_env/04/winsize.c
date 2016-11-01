#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <unistd.h>
#include <termios.h>


#if defined(__APPLE__) && defined(__MACH__)
#define	IOCTL		<sys/ioctl.h>
#elif defined(unix)
# ifndef TIOCGWINSZ
#define	IOCTL		<sys/ioctl.h>
# endif  //TIOCGWINSZ
#else 
#define	IOCTL
#endif	//

#include IOCTL


static void
pr_winsize(int fd)
{
    struct winsize size;

    ioctl(fd, TIOCGWINSZ, &size);

    printf("%d rows, %d columns\n", size.ws_row, size.ws_col);
}


static void sig_winch(int errno)
{
    printf("SIGWINCH receiced\n");
    pr_winsize(STDIN_FILENO);
}


int
main(int argc, char* argv[])
{
    if (isatty(STDIN_FILENO) == 0)
    {
        exit(EXIT_FAILURE);
    }

    if (signal(SIGWINCH, sig_winch) == SIG_ERR)
    {
        exit(EXIT_FAILURE);
    }

    pr_winsize(STDIN_FILENO);

    for (;;)
        pause();

    return EXIT_SUCCESS;
}
