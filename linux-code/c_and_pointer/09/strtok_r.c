#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <limits.h>


#define SET         (1)

#define NUL         '\0'


static void 
set_hash(char* restrict hash, const char* restrict seg)
{
    do {

        hash[*seg] = SET;

    } while (*seg++ != NUL);
}

static char*
strtok_r(char* restrict dest, const char* restrict seg, char** restrict lasts)
{
    char* tmp = NULL;
    char hash[CHAR_MAX] = {0};

    if ((dest==NULL) && (*lasts==NULL))
    {
        return NULL;
    }

    tmp = (dest!=NULL) ? dest : *lasts;
    dest = tmp;

    set_hash(hash, seg);

    while (hash[*tmp] != SET)
    {
        tmp++;
    }

    *lasts = (*tmp==NUL) ? NULL : (tmp+1);
    *tmp = NUL;

    return dest;
}

static char*
strsep(char** restrict pstring, const char* restrict seg)
{
    char hash[CHAR_MAX] = "";
    char* tmp = *pstring;

    if (*pstring == NULL)
    {
        return NULL;
    }

    set_hash(hash, seg);
    while (hash[**pstring] != SET)
    {
        (*pstring)++;
    }

    if (**pstring == NUL)
    {
        *pstring = NULL;
    }
    else
    {
        *(*pstring)++ = NUL;
    }

    return tmp;
}

int
main(int argc, char* argv[])
{
    char* word = NULL;
    char* keep = NULL;
    char buffer[] = "123.456,789,1";
    char string[] = "123.456.789,1";
    const char seg[] = ".,";
    char* pstring = string;

    for (word = strtok_r(buffer, seg, &keep);
            word != NULL;
         word = strtok_r(NULL, seg, &keep))
    {
        printf("%s\n", word ? word : "null");
    }

    for (word = strsep(&pstring, seg);
            word != NULL;
         word = strsep(&pstring, seg))
    {
        printf("%s\n", word);
    }

    return EXIT_SUCCESS;
}
