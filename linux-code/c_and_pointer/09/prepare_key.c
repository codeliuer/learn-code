#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define F           ('A')
#define E           ('Z')
#define N           (E-F+1)


#define INDEX(c)    (toupper(c)-F)
#define GET(x)      ((x)+F)

#define FALSE       (0)
#define TRUE        (1)

#define CLR         (0)
#define SET         (1)

#define NUL         ('\0')


typedef unsigned char       bool;


static bool
set_key_hash(char* hash, const char* key)
{
    while ((*key!=NUL) && isalpha(*key))
    {
        hash[INDEX(*key)] = SET;
        key++;
    }

    return (*key==NUL) ? TRUE : FALSE;
}

static char
get_hash_char(char* hash, int num)
{
    int i = 0;

    for (i = 0; i < num; i++)
    {
        if (hash[i] != SET)
        {
            hash[i] = SET;

            return GET(i);
        }
    }
}

static int 
prepare_key(char* key)
{
    size_t key_len = strlen(key);
    char hash_str[N] = "";


    if (set_key_hash(hash_str, key) == FALSE)
    {
        return FALSE;
    }

    key = key+key_len;

    while (key_len++ <= N)
    {
        *key++ = get_hash_char(hash_str, N); 
    }

    return TRUE;
}


static void
encrypt(char* data, char const* key)
{
}


static void 
decrypt(char* data, char const* key)
{
}


int
main(int argc, char* argv[])
{
    char key[N] = "TRAILBLAZERS";

    prepare_key(key);
    printf("%s\n", key);

    return EXIT_SUCCESS;
}
