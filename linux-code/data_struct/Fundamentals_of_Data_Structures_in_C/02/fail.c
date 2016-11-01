#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


static void* 
get_memory(size_t size)
{
    void* tmp = malloc(size);
    assert(tmp);

    return tmp;
}

static void
fail(char* failure, const char* find_sub)
{
    int i = 0;
    int j = 0;
    int len = strlen(find_sub);

    failure[0] = -1;

    for (i = 1; i < len; i++)
    {
        j = failure[i-1];
        while ((find_sub[i] != find_sub[j+1]) && (j != -1))
        {
            j = failure[j];
        }
        if (find_sub[i] == find_sub[j+1])
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
match(const char* restrict string, const char* restrict sub, char* restrict failure)
{
    int i = 0;
    int j = 0;
    size_t string_len = strlen(string);
    size_t sub_len = strlen(sub); 

    for (i = 0, j = 0; i < string_len && j < sub_len; )
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
            j = failure[j-1]+1;
        }
    }

    return (j == sub_len) ? (char *)&string[i-sub_len] : NULL;
}

static void 
show(char* restrict failure, size_t num)
{
    int i = 0;

    for (i = 0; i < num; i++)
    {
        printf("%d  ", failure[i]);
    }
    printf("\n");
}

static void 
find_string(const char* string, const char* find_sub)
{
    char* ptr = NULL;
    char* failure = NULL;
    size_t len = strlen(find_sub);

    failure = get_memory(len+1);
    fail(failure, find_sub);
    show(failure, len);

    ptr = match(string, find_sub, failure);
    printf("string = %p\n", string);
    printf("ptr = %p\n", ptr);
}


int
main(int argc, char* argv[])
{
    find_string("aaaaaaccccccbbbbb", "aaaaac");

    return EXIT_SUCCESS;
}
