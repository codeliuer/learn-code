#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <unistd.h>
#include <fcntl.h>


#define RSHIFT(c, base)         ((((c)-(base))+13)%26+(base))


static int translate(int c)
{
    if (isupper(c))
    {
        return RSHIFT(c, 'A');
    }
    else if (islower(c))
    {
        return RSHIFT(c, 'a');
    }
    else
    {
        return c;
    }
}

int main(int argc, char *argv[])
{
    int i = 0;
    int n = 0;
    int w = 0;
    int ifd = 0;
    int ofd = 0;
    int len = 0;
    char buffer[BUFSIZ] = "";

    if (argc != 3)
    {
        fprintf(stderr, "parameter failure\n");
        return EXIT_FAILURE;
    }

    if ((ifd = open(argv[1], O_RDONLY)) < 0)
    {
        fprintf(stderr, "open failure\n");
        return EXIT_FAILURE;
    }

    if ((ofd = open(argv[2], O_RDWR|O_TRUNC|O_CREAT, 0666)) < 0)
    {
        exit(EXIT_FAILURE);
    }

    while ((n = read(ifd, buffer, sizeof(buffer))) > 0)
    {
        for (i = 0; i < n; i++)
        {
            buffer[i] = translate(buffer[i]);
        }

        if ((w = write(ofd, buffer, n)) != n)
        {
            fprintf(stderr, "write failure\n");
        }
    }

    fsync(ofd);

    return EXIT_SUCCESS;
}
