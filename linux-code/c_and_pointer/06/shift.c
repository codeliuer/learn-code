#include <stdio.h>
#include <stdlib.h>


#define DEC_SYSTEM          (10)


static int 
l_atoi(const char *str)
{
    int num = 0;

    /* jump space */
    while ((*str == '\n') || (*str == ' ') || (*str == '\r')
            || (*str == '\f') || (*str == '\v') || (*str == '\t'))
    {
        str++;
    }

    if (*str == '\0')
    {
        return num;
    }

    while ((*str >= '0') && (*str <= '9'))
    {
        num = DEC_SYSTEM * num + *str++ - '0';
    }
    printf("num = %d\n", num);

    return num;
}


static int 
l_strlen(const char *string)
{
    int len = 0;

    while (*string++ != '\0')
    {
        len++;
    }

    return len;
}


static void 
shift(char *string, int position)
{
    int i = 0;
    int j = 0;
    int sl = l_strlen(string);
    char buffer[sl];

    for (i = 0; i < sl; i++)
    {
        if (position + i < sl)
        {
            buffer[i] = string[position+i];
        }
        else
        {
            buffer[i] = string[j++];
        }
    }

    for (i = 0; i < sl; i++)
    {
        string[i] = buffer[i];
    }
}


int
main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: ./a.out string localtion\n");
        return EXIT_FAILURE;
    }

    shift(argv[1], l_atoi(argv[2]));
    printf("%s\n", argv[1]);

    return EXIT_SUCCESS;
}
