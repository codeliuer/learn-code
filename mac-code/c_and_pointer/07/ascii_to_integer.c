#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NUL                 '\0'

#define OCT_SYSTEM          (010)
#define DEC_SYSTEM          (10)
#define HEX_SYSTEM          (0x10)

#define SYSTEM              HEX_SYSTEM


static int 
isgal(char c, int system)
{
    if (system == OCT_SYSTEM)
    {
        return (c >= '0') && (c <= '8');
    }
    else if (system == DEC_SYSTEM)
    {
        return (c >= '0') && (c <= '9');
    }
    else
    {
        return ((c >= '0') && (c <= '9')) 
               || ((c >= 'a') && (c <= 'f'))
               || ((c >= 'A') && (c <= 'F'));
    }
}


static int 
char_to_int(char c)
{
    switch (c)
    {
    case '0':   case '1':   case '2':   case '3':
    case '4':   case '5':   case '6':   case '7':
    case '8':   case '9':
        return c - '0';
        break;
    case 'a':   case 'b':   case 'c':   case 'd':
    case 'e':   case 'f':
        return c - 'a' + DEC_SYSTEM;
        break;
    case 'A':   case 'B':   case 'C':   case 'D':
    case 'E':   case 'F':
        return c - 'A' + DEC_SYSTEM;
        break;
    default:
        return 0;
        break;
    }
}


static int 
ascii_to_integer(const char* string)
{
    int sum = 0;

    while (*string)
    {
        if (!isgal(*string, SYSTEM))
        {
            return 0;
        }

        sum = SYSTEM * sum + char_to_int(*string++);
    }

    return sum;
}


int
main(int argc, char* argv[])
{
    char buffer[BUFSIZ] = "";

    while (fgets(buffer, sizeof(buffer), stdin))
    {
        buffer[strlen(buffer)-1] = NUL;
        printf("%d\n", ascii_to_integer(buffer));
    }

    return EXIT_SUCCESS;
}
