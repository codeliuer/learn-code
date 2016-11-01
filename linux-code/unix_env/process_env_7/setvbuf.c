#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


static char databuf[BUFSIZ] = "";


static FILE *
open_data(const char* filename)
{
    FILE *fp = NULL;
    
    if ((fp = fopen(filename, "r")) == NULL)
    {
        return NULL;
    }

    setvbuf(fp, databuf, _IOFBF, sizeof(databuf));
    printf("!!!!!!!!!!!\n%s\n!!!!!!!!!!!!!", databuf);

    return fp;
}


int
main(int argc, char* argv[])
{
    char* ptr = NULL;
    char test[BUFSIZ] = "";

    if (argc < 2)
    {
        fprintf(stderr, "Usage: ./a.out filename\n");
        exit(EXIT_FAILURE);
    }

    FILE *pfile = open_data(argv[1]);

    ptr = fgets(test, sizeof(test), pfile);
    printf("%s", ptr);

    printf("%s\n", databuf);
/*
    while ((ptr = fgets(test, sizeof(test), pfile)) != NULL)
    {
        printf("%s", ptr);
    }
*/
    return EXIT_SUCCESS;
}
