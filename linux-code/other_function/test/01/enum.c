/*
** enum.c 
** enum
**
** Created by liuwei on 16/10/4
** Copyright @ 2016y git. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TOKEN_t
{
    enum E_t
    {
        lparen, rparen, TAG_MAX,
    }e;
    char arr[TAG_MAX]; 
    enum E_t (* FIND_t)(char c);
    void (* print)(enum E_t);
} TOKEN_t;


static void print(enum E_t e);


static TOKEN_t token =
{
    .e     = lparen,
    .arr   = {'(', ')', }, 
    .print = print,
};


static void
print(enum E_t e)
{
}


int
main(int argc, char *argv[])
{
    if (lparen < 0)
    {
        printf("int \n");
    }

    return EXIT_SUCCESS;
}
