/*
** test setjmp
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>


static void f1(int, int, int, int);
static void f2(void);


static jmp_buf jmpbuffer;
static int global;


int
main(int argc, char* argv[])
{
    int autoval = 0;
    register int regival = 0;
    volatile int volaval = 0;
    static int statval = 0;

    global = 1, autoval = 2, regival = 3, volaval = 4, statval = 4;

    if (setjmp(jmpbuffer) != 0)
    {
        printf("after longjmp\n");
        printf("global = %d, autoval = %d, regival = %d,"
                " volatile = %d, statval = %d\n",
                global, autoval, regival, volaval, statval);
        exit(0);
    }
    
    /*
    ** change variables after setjmp, but before longjmp
    */
    global = 95, autoval = 96, regival = 97, volaval = 98;
    statval = 99;

    f1(autoval, regival, volaval, statval); /* never returns */

    return EXIT_SUCCESS;
}


static void
f1(int i, int j, int k, int l)
{
    printf("in f1(): \n");
    printf("gloval = %d, autoval = %d, regival = %d,"
            " volaval = %d, statval = %d\n", 
            global, i, j, k, l);

    f2();
}


static void
f2(void)
{
    longjmp(jmpbuffer, 1);
}
