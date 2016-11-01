#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void
print(unsigned char times)
{
    char i = 0;

    /* (char)-6 ---> (int)-6 */
    for (i = 0; i < times; i++)
    {
        printf("Loop: %d\n", i);
    }
}


int
main(int argc, char * argv[])
{
    int c = 0;
    unsigned char times = 200;
//    print(times);

    c = (char)127 + (char)1;
    printf("%d\n", (char)127+(char)1);
    printf("c = %d\n", c);

    return EXIT_SUCCESS;
}
