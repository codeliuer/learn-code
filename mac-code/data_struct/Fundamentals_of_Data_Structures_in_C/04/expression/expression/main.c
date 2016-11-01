//
//  main.c
//  expression
//
//  Created by weiliu on 16/10/4.
//  Copyright © 2016year git. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


#ifndef true
#define true        (1)
#endif //true

#ifndef false
#define false       (0)
#endif //false

#define infinite    for(;;)


enum TOKEN
{
    lparen, rparen, plus, minus, mul, divisi, mod, eol, oparent, TAG_MAX,
};

typedef struct TOKEN_t
{
    char token_arr[TAG_MAX];
    int (* get_token)(enum TOKEN);
    int (* print_token)(enum TOKEN);
} TOKEN_t;


static int get_token_f(enum TOKEN token);
static int print_token_f(enum TOKEN token);

static TOKEN_t g_token =
{
    .token_arr = {'(', ')', '+', '-', '*', '/', '%',},
    .get_token = get_token_f,
    .print_token = print_token_f,
};


/**
 *
 */
static int
get_token_f(enum TOKEN token)
{
    if (token >= TAG_MAX)
    {
        return false;
    }
    
    return g_token.token_arr[token];
}

static int
print_token_f(enum TOKEN token)
{
    if (token >= TAG_MAX)
    {
        return false;
    }
    
    printf("%c\n", g_token.get_token(token));
    
    return true;
}


int main(int argc, const char * argv[])
{
    g_token.print_token(lparen);
    
    return EXIT_SUCCESS;
}