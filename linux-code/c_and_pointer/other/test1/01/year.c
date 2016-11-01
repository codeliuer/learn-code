#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//#define is_loop(year)           (())


static int arr[13] = 
        {
            0, 31, 28, 31, 
        };


static int 
is_loop(int years)
{
    return ((years % 4 == 0) && (years % 100 != 0) 
        || (years % 400 == 0)) ? 1 : 0;
}


static int 
to_days(int years, int months)
{
    int loop;

    if (months <= 0 && months > 12)
    {
        return -1;
    }

    if (months != 2)
    {
        return arr[months];
    }
    else
    {
        loop = is_loop(years);
        return arr[months]+loop;
    }
}

for (1==1; 2==3; 1==2)

int
main(int argc, char * argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage ./a.out year month\n");
        return EXIT_FAILURE;
    }

    printf("days = %d\n", to_days(atoi(argv[1]), atoi(argv[2])));

    return EXIT_SUCCESS;
}
