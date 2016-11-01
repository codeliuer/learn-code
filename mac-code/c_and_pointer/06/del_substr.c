#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


static void*
alloc(size_t size)
{
    void* ptr = malloc(size);
    assert(ptr);

    return ptr;
}


#define malloc  ban_call_malloc!!!

#define MALLOC(size, type)  (type *)alloc(sizeof(type) * (size))

static void
fail(int* restrict failure, const char* sub)
{
    int i = 0;
    int j = 0;
    int sub_len = strlen(sub);

    failure[0] = -1;

    for (i = 1; i < sub_len; i++)
    {
        j = failure[i-1];
        if ((sub[i] != sub[j+1]) && (j != -1))
        {
            j = failure[j];
        }
        else if (sub[i] == sub[j+1])
        {
            failure[i] = j+1;
        }
        else
        {
            failure[i] = -1;
        }
    }
}

static char* 
find_substring(const char* restrict string, const char* restrict sub)
{
    int i = 0;
    int j = 0;
    int sub_len = strlen(sub);
    int string_len = strlen(string);
    int* failure = MALLOC(strlen(sub), int);

    fail(failure, sub);

    for (i = 0, j = 0; (i<string_len) && (j<sub_len); )
    {
        if (string[i] == sub[j])
        {
            i++, j++;
        }
        else if (j == 0)
        {
            i++;
        }
        else
        {
            j = failure[j]+1;
        }
    }

    return (j==sub_len) ? (char *)&string[i-sub_len] : NULL;
}

int
main(int argc, char* argv[])
{
    char* str = find_substring("123454321asderfdefefeaaaa", "efefe");

    printf("%s\n", str);

    return EXIT_SUCCESS;
}
