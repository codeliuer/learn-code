//
//  main.c
//  sort
//
//  Created by 伟刘 on 16/10/6.
//  Copyright © 2016年 git. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define NUL				'\0'

#define MAX_STRING		(100)


typedef int (* CMP_t)(const void *, const void *);


static int
cmp_string(const void *key1, const void *key2)
{
    const char *s1 = *(const char **)key1;
    const char *s2 = *(const char **)key2;
    
    return strcmp(s1, s2);
}


static void
get_string(char **string, int n)
{
    int i = 0;
    int len = 0;
    char buffer[MAX_STRING+1] = "";
    
    for (i = 0; i < n; i++)
    {
        fgets(buffer, sizeof(buffer), stdin);
        len = (int)strlen(buffer);
       	if (buffer[len-1] == '\n')
        {
            buffer[--len] = NUL;
        }
        
        string[i] = (char *)malloc(len+1);
        strcpy(string[i], buffer);
    }
}


#define SWAP(arr, tmp, brr, size)	\
    do {							\
        memcpy(tmp, arr, size);		\
        memcpy(arr, brr, size);		\
        memcpy(brr, tmp, size);		\
    } while (0)


static void
sort(void *arr, size_t size, int n, CMP_t cmp)
{
    int i = 0;
    int last = 0;
    int mid = n / 2;
    char *brr = (char *)arr;
    char *tmp = (char *)malloc(size);
    
    if (n <= 1)
    {
        return;
    }
    
    SWAP(brr, tmp, brr+mid*size, size);
    for (i = 1; i < n; i++)
    {
        if (cmp(brr, brr+i*size) > 0)
        {
            last++;
            SWAP(brr+last*size, tmp, brr+i*size, size);
        }
    }
    SWAP(brr, tmp, brr+last*size, size);
    
    free(tmp), tmp = NULL;
    
    sort(brr, size, last, cmp);
    sort(brr+size*(last+1), size, n-last-1, cmp);
}


static void
print_string(char **string, int n)
{
    int i = 0;
    
    for (i = 0; i < n; i++)
    {
        printf("%s\n", string[i]);
        
        free(string[i]), string[i] = NULL;
    }
}


int
main(int argc, char *argv[])
{
    int n = 0;
    char **string = NULL;
    
    scanf("%d", &n);
    
    scanf("%*[^\n]");
    scanf("%*c");
    
    string = (char **)malloc(sizeof(char *) * n);
    assert(string != NULL);
    
    get_string(string, n);
    sort((void *)string, sizeof(char *), n, cmp_string);
    print_string(string, n);
    
    free(string), string = NULL;
    
    return EXIT_SUCCESS;
}
