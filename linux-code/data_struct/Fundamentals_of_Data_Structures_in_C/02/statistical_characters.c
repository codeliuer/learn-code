#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define NUL             ('\0')

#define arr_num(arr)    (sizeof(arr)/sizeof(arr[0]))


static int statis_ch(const char* string, int* arr)
{
    int total = strlen(string);

    while (*string != NUL)
    {
        arr[*string++]++;
    }

    return total;
}

static void 
show(int* arr, int num, int total)
{
    int i = 0;

    printf("character total = %d\n", total);
    for (i = 0; i < num; i++)
    {
        if (arr[i] != 0)
        {
            printf("%1c: %-4d: %4.4lf\n",  i, arr[i], (double)arr[i]/total);
        }
    }
}

static void
clear_data(int* arr, int num)
{
    int i = 0;

    for (i = 0; i < num; i++)
    {
        arr[i] = 0;
    }
}

int
main(int argc, char* argv[])
{
    int total = 0;
    int num[CHAR_MAX] = {0};
    char string[BUFSIZ] = "";

    while (fgets(string, sizeof(string), stdin) != NULL)
    {
        string[strlen(string)-1] = NUL;
        total = statis_ch(string, num);
        show(num, arr_num(num), total);
        clear_data(num, arr_num(num));
    }

    return EXIT_SUCCESS;
}
