#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define TRUE            (0)
#define FALSE           (1)

#define S               ('A')
#define E               ('Z')
#define N               (E-S+1)

#define TRAN(c)         (toupper(c))
#define GETC(c)         (S+c)
#define INDEX(c)        (TRAN(c)-S)

#define CLR             (0)
#define SET             (1)

#define NUL             ('\0')


typedef unsigned char   bool;


static bool 
check_key(const char* restrict key)
{
    while (isalpha(*key))
    {
        key++;
    }

    return (*key==NUL) ? TRUE : FALSE;
}

static void 
remove_dup(unsigned char* restrict hash, char* restrict key)
{
    int i = 0;
    int j = 0;
    int len = strlen(key);

    for (j = 0; j < len; j++)
    {
        if (hash[INDEX(key[j])] != SET)
        {
            hash[INDEX(key[j])] = SET;
            key[i++] = TRAN(key[j]);
        }
    }

    key[i] = NUL;
}

static unsigned char
find_clr(char* restrict hash)
{
    int i = 0;

    for (i = 0; i < N; i++)
    {
        if (hash[i] != SET)
        {
            hash[i] = SET;
            return GETC(i);
        }
    }
}

static void
expand_key(char* key, unsigned char* restrict hash)
{
    int len = strlen(key);

    while (len < N)
    {
        key[len++] = (char)find_clr(hash);
    }

    key[len] = NUL;
}

static int 
prepare_key(char* key)
{
    unsigned char hash[N] = "";

    if (check_key(key) == FALSE)
    {
        return FALSE;
    }

    remove_dup(hash, key);
    expand_key(key, hash);

    return TRUE;
}

static void
encrypt(char* restrict data, const char* restrict key)
{
    int i = 0;
    int ch;
    int len = strlen(data);

    for (i = 0; i < len; i++)
    {
        if (!isalpha(data[i]))
        {
            continue;
        }

        ch = key[INDEX(data[i])];
        data[i] = isupper(data[i]) ? toupper(ch) : tolower(ch);
    }
}

static void
decrypt(char* restrict data, const char* restrict key)
{
    int i = 0;
    char* tmp = NULL;
    int poor = 0;
    int len = strlen(data);

    for (i = 0; i < len; i++)
    {
        if (!isalpha(data[i]))
        {
            continue;
        }

        tmp = strchr(key, TRAN(data[i]));
        poor = tmp - key;
        data[i] = isupper(data[i]) ? toupper(GETC(poor)) : tolower(GETC(poor)) ;
    }
}

int
main(int argc, char* argv[])
{
    char data[] = "AaaaaA111a34dfgsdf.";
    char key[N+1] = "TRAILBLAZERS";

    if (prepare_key(key) == TRUE)
    {
        printf("%s\n", key);
    }
    
    printf("origin: %s\n", data);
    encrypt(data, key);
    printf("encrypt: %s\n", data);

    decrypt(data, key);
    printf("decrypt: %s\n", data);

    return EXIT_SUCCESS;
}
