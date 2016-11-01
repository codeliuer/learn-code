//
//  main.c
//  helix
//
//  Created by liuwei on 16/10/5.
//  Copyright © 2016y git. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>


#define infinite            for (;;)

#define STACK_DEPTH         (10)

#define ARR_NUM(arr)        (sizeof(arr)/sizeof(arr[0]))


#define debug_print()       printf("%s[%d]: ", __func__, __LINE__)


typedef enum TOKEN_t
{
    lparen, rparen, plus, minus, mul, divisi, mod, operant, eol, BAD_TAG,
} TOKEN_t;

static char chrarr[] = {'(', ')', '+', '-', '*', '/', '%'};


static int sinpri[] = {0, 19, 12, 12, 13, 13, 13, 0};
static int soutpri[] = {20, 19, 12, 12, 13, 13, 13, 0};

static int top = -1;
static TOKEN_t stack_token[STACK_DEPTH] = {0};


static TOKEN_t
find_char(char chr)
{
    int i = 0;
    
    for (i = 0; i < ARR_NUM(chrarr); i++)
    {
        if (chrarr[i] == chr)
        {
            return i;
        }
    }

    return BAD_TAG;
}


static void
print_token(TOKEN_t token)
{
    printf("%c ", chrarr[token]);
}


static void
push_stack(TOKEN_t token)
{
    if (top >= STACK_DEPTH)
    {
        debug_print();
        printf("stack depth = %d\n", top);
        
        return;
    }
    
    stack_token[++top] = token;
}

static TOKEN_t
pop_stack(void)
{
    if (top == -1)
    {
        debug_print();
        printf("stack empty\n");
        
        return BAD_TAG;
    }
    
    return stack_token[top--];
}

static TOKEN_t
top_stack(void)
{
    if (top == -1)
    {
//        debug_print();
//        printf("stack empty\n");
        
        return BAD_TAG;
    }
    
    return stack_token[top];
}


static TOKEN_t
get_token(int *symbol)
{
    int ch;
    TOKEN_t token;
    
    while (isspace(ch = getchar()));
    
    if (isdigit(ch))
    {
        token = operant;
        *symbol = ch - '0';
        
        while (isdigit(ch = getchar()))
        {
            *symbol = 10 * *symbol + ch - '0';
        }
        
        if (ch != EOF)
        {
            ungetc(ch, stdin);
        }
        
        return token;
    }
    else if ((token = find_char(ch)) != BAD_TAG)
    {
        return token;
    }
    
    return eol;
}


/** The infix expression into a postfix expression
 *
 */
static void
postfix(void)
{
    int symbol;
    TOKEN_t token;
    
    while ((token = get_token(&symbol)) != eol)
    {
        if (token == operant)
        {
            printf("%d ", symbol);
        }
        else if (token == rparen)
        {
            while (top_stack() != lparen)
            {
                print_token(pop_stack());
            }
			pop_stack();
        }
        else
        {
            while ((top_stack() != BAD_TAG) && (soutpri[token] <= sinpri[top_stack()]))
            {
                print_token(pop_stack());
            }
            push_stack(token);
        }
    }
    
    while (top_stack() != BAD_TAG)
    {
        print_token(pop_stack());
    }
}


int
main(int argc, char *argv[])
{
    setvbuf(stdout, NULL, _IONBF, 0);
    
    debug_print();
    
    postfix();
    printf("\n");

    return EXIT_SUCCESS;
}



