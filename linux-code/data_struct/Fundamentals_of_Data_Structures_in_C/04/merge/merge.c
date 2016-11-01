/*
** merge sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ELENUM(arr)             (sizeof(arr)/sizeof(arr[0]))


enum 
{
    INT, 
#define INT         INT
    STRING,
#define STRING      STRING
};


typedef int (* PRINT_t)(void *, int);

typedef int (*CMP_t)(const void *, const void *);


int
cmp_int(const void *key1, const void *key2)
{
    const int data1 = *(const int *)key1;
    const int data2 = *(const int *)key2;

    return (data1-data2);
}


int 
cmp_string(const void *key1, const void *key2)
{
    const char *data1 = *(const char **)key1;
    const char *data2 = *(const char **)key2;

    return strcmp(data1, data2);
}


static void 
copy_to_dest(char *dest, char *src, size_t size, size_t len)
{
    size_t i = 0;

    for (i = 0; i < len; i++)
    {
        memcpy(dest+size*i, src+size*i, size);
    }
}

static void
merger_ele(char *arr, char *barr, size_t size, size_t len, CMP_t cmp)
{
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    size_t mid = len/2;
    size_t com_i = 0;
    size_t com_j = 0;

    for (i = 0, j = mid; i < mid && j < len; )
    {
        if (cmp(arr+size*i, arr+size*j) < 0)
        {
            memcpy(barr+size*k, arr+size*i, size);
            i++;
        }
        else
        {
            memcpy(barr+size*k, arr+size*j, size);
            j++;
        }

        k++;
    }

    com_i = (i == mid) ? j : i;
    com_j = (i == mid) ? len : mid;

    for (; com_i < com_j; com_i++)
    {
        memcpy(barr+size*k++, arr+size*com_i, size);
    }

    copy_to_dest(arr, barr, size, len);
}

static void 
sort(char *arr, char *barr, size_t size, size_t len, CMP_t cmp)
{
    size_t mid = len/2;

    if (len < 2)
    {
        return;
    }
    
    sort(arr, barr, size, mid, cmp);
    sort(arr+mid*size, barr+mid*size, size, len-mid, cmp);

    merger_ele(arr, barr, size, len, cmp);
}


int 
merge(void *arr, size_t size, size_t len, CMP_t cmp)
{
    char *ptr = (char *)malloc(size * len);

    sort(arr, ptr, size, len, cmp);

    free(ptr), ptr = NULL;

    return 0;
}


static int 
show_int(void *arr, int num)
{
    int i = 0;
    int *brr = (int *)arr;

    for (i = 0; i < num; i++)
    {
        printf("%d--", brr[i]);
    }
    printf("\n");
}


static int 
show_string(void *arr, int num)
{
    int i = 0;
    char **brr = (char **)arr;

    for (i = 0; i < num; i++)
    {
        printf("%s\n", brr[i]);
    }
}


int
print(void *arr, int num, int type)
{
    PRINT_t show[] = 
        {
            show_int,       show_string,
        };

    show[type](arr, num);
}


#define merge_int(arr, len)     merge(arr, sizeof(int), len, cmp_int)
#define merge_string(arr, len)  merge(arr, sizeof(char *), len, cmp_string)

#define print_int(arr, len)     print(arr, len, INT)
#define print_string(arr, len)  print(arr, len, STRING)


static void
test_int(void)
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1,};

    merge_int(arr, ELENUM(arr));
    print_int(arr, ELENUM(arr));
}


static void
test_string(void)
{
    char *arr[] = 
        {
            "liuwei",   "suchuan", "linhaijin", "meidongting", "liuwei", "huzhaohui",
            "wangzhiqiang", "lijianhua", "maoxiaozhou", "qiaozhenghui", "hushengyang", 
            "heshuangyang", "xiaohuajun",
        };

    merge_string(arr, ELENUM(arr));
    print_string(arr, ELENUM(arr));
}


int
main(int argc, char * argv[])
{
    test_int();
    test_string();


    return EXIT_SUCCESS;
}
