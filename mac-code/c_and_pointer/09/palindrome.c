#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define FALSE           (0)
#define TRUE            (1)


typedef unsigned char   bool;


static bool
palindrome(const char* string)
{
    const char* end = string+strlen(string)-1;

    while (string < end)
    {
        if (isalpha(*string) && isalpha(*end))
        {
            if (tolower(*string) == tolower(*end))
            {
                string++, end--;
            }
            else
            {
                return FALSE;
            }
        }
        else if (!isalpha(*string))
        {
            string++;
        }
        else
        {
            end--;
        }
    }

    return TRUE;
}


int
main(int argc, char* argv[])
{
    printf("%s\n", palindrome("12356asAaa ASa654321")?"YES":"NO");
    printf("%s\n", palindrome("1235a6asAa  ASa6543a21")?"YES":"NO");
    printf("%s\n", palindrome("a1235 a a")?"YES":"NO");

    return EXIT_SUCCESS;
}
