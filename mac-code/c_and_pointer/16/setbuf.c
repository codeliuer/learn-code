#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NUL             '\0'


//#undef NUL


int
main(int argc,char* argv[])
{
    char buffer[BUFSIZ] = "";
    /*
    setbuf(stdout, buffer);

    printf("%s", "test event");
    sleep(1);
    printf("%lu", strlen(buffer));
    buffer[0] = NUL;
    buffer[1] = NUL;
    buffer[2] = NUL;
    buffer[3] = NUL;
    buffer[4] = NUL;
    buffer[5] = NUL;
    buffer[6] = NUL;
    buffer[7] = NUL;
    buffer[8] = NUL;
    */

    //fflush(stdout);
    /*printf("%d\n", system(NULL));
    system("ls -a -l");
    */

    if (system(NULL))
    {
        system("pwd");
        system("ls -al");
    }
    else
    {
        printf("not exist system command deal tool\n");
    }

    exit(EXIT_SUCCESS);
}
