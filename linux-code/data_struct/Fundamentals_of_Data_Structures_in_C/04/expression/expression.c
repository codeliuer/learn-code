/*
** The infix expression into a postfix expression
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define UNUSED(x)           ((void)(x))


typedef enum TOKEN_t
{
    lparen, rparen, plus, minus, mul, divisi, mod, eol, MAX,
} TOKEN_t;


typedef struct STACK_t 
{
    char    sinpri[MAX];        // stack in priority
    char    soutpri[MAX];       // stack out priority 
    int     (*CMP_t)(TOKEN_t);
    int     (*STACK_top)(void);
    int     (*STACK_push)(int);
    int     (*STACK_pop)(void);
} STACK_t;


static int cmp_stack(TOKEN_t t1);
static int top_stack(void);


static STACK_t stack = 
{
    {0, 19, 12, 12, 13, 13, 13, 0},
    {20, 19, 12, 12, 13, 13, 13, 0},
    cmp_stack,
    top_stack,
    push_stack,
    pop_stack,
};


static char
pop_stack(void)
{
    char c;

    return c;
}


static int 
push_stack(char data)
{
}


static int 
top_stack(void)
{
}


static int 
pop_stack(void)
{
}



static int 
cmp_stack(TOKEN_t t)
{
    return stack.soutpri[t] > stack.STACK_top() ? 1 : 0;
}


int
main(int argc, char *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    return EXIT_SUCCESS;
}
