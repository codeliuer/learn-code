#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <unistd.h>
#include <fcntl.h>


int arr[] = 
{
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
    'u', 'v', 'w', 'x', 'y', 'z',
};


int main(int argc, char *argv[])
{
    int i = 0;
    int k = 0;
    int fd = 0;
    int nums = 0;
    const int max = 100000000;
    const char *filename = "string.txt";
    char buffer[12] = "";;

    fd = open(filename, O_RDWR);
    if (fd < 0)
    {
        fprintf(stderr, "open file failure\n");
        return EXIT_SUCCESS;
    }

    srand(time(NULL));

    while (i++ < max)
    {
        nums = rand() % 10 + 1;

        memset(buffer, 0, 12);
        
        for (k = 0; k < nums; k++)
        {
            buffer[k] = arr[rand()%26];
        }

        buffer[k] = '\n';

        write(fd, buffer, k+1);
    }

    close(fd);

    return EXIT_SUCCESS;
}
