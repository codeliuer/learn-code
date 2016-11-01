/*
** compare the super used created files and ordinary
** user to create the file permissions
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>


int
main(int argc, char* argv[])
{
    int fd = 0;
    char buffer[BUFSIZ] = "";

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./a.out ");
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror(argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
