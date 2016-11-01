/*
** test variable length arrays
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define offset_of(type, member)     (size_t)&((type *)0)->member


typedef struct FORMAT_t 
{
    int             id;
    char*           pname[];
} FORMAT_t;


typedef struct TEST_INFO_t
{
    int         length;
    int         caca;
    char*       pname;
    char        a;
    FORMAT_t    format;
} TEST_INFO_t;


typedef struct ARRAY_t
{
    int         arr;
    int         str[];
} ARRAY_t;

struct NODE
{
    int a;
    int b[];
};

union U
{
    struct NODE noe;
    int a;
};

typedef struct CHAR_t
{
    int         a;
    char        c;
    char        d[];
} CHAR_t;

typedef struct CHAR2_t
{
    char        c;
    int         a;
    char        d[];
} CHAR2_t;

struct NOTE
{
    /*
    ** error: the flexible array is member of structure
    ** and the structure with more than one named member
       //\
    int         arr[];*/
};

static size_t off = offset_of(TEST_INFO_t, format);

static const int a  = 3;
//static FORMAT_t format = {0, "liuwei"};
//static TEST_INFO_t info = {10, 20, NULL, {0, "name"};
static ARRAY_t array = {10, 1, 2, 3, 4, 5, 6};

int
main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;

    a = b//**/0
        + a;

    printf("%d\n", array.str[1]);
    printf("%ld\n", sizeof(union U));
//    printf("%ld\n", offset_of(TEST_INFO_t, arr));
//    printf("%ld\n", offset_of(TEST_INFO_t, pname));
//    printf("%ld\n", offset_of(TEST_INFO_t, caca));
//    printf("%ld\n", sizeof(test));
//    printf("sizeof(array) = %ld\n", sizeof(array));
//    printf("sizeof(struct NODE) = %ld\n", sizeof(struct NODE));
//    printf("%s\n", test.arr[2].pname[]);
//    printf("%d\n", array.str[5]);
    printf("%ld\n", off);

    printf("CHAR_t = %ld\n", offset_of(CHAR_t, d));
    printf("CHAR2_t = %ld\n", offset_of(CHAR2_t, d));

    return EXIT_SUCCESS;
}
