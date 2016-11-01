#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define NUL             '\0'

#define SET             1


static void
parse_chars(char* restrict hash, const char* restrict chars)
{
    while (*chars != NUL)
    {
        hash[*chars++] = SET;
    }
}

static size_t
count_chars(const char* restrict str, const char* restrict chars)
{
    size_t count = 0;
    char hash[CHAR_MAX] = "";

    parse_chars(hash, chars);

    while (*str != NUL)
    {
        if (hash[*str++] == SET)
        {
            count++;
        }
    }

    return count;
}

int
main(int argc, char* argv[])
{
    printf("%0lu\n", count_chars("1234567890asd", "qawszxcd"));

    return EXIT_SUCCESS;
}
