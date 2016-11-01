//
//  src.c
//  postfix
//
//  Created by weiliu on 16/10/5.
//  Copyright © 2016year git. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "src.h"


typedef enum TOKEN_t
{
    lparen, rparen, plus, minus, mul, divisi, greater, less, mod, TAG_MAX, eol, operant, BAD_TAG,
} TOKEN_t;

typedef struct ALL_t
{
    char arr[TAG_MAX];
    int sinpri[TAG_MAX];
    int soutpri[TAG_MAX];
    char (* get_char)(TOKEN_t);
    int (* print_token)(TOKEN_t);
    int (* cmp)(TOKEN_t, int);
    TOKEN_t (* find_char)(char);
} ALL_t;

typedef struct STACK_t
{
    TOKEN_t token;
    struct STACK_t *next;
} STACK_t;

typedef struct FUNC_STACK_t
{
    STACK_t *head;
    TOKEN_t (* top_stack)();
    TOKEN_t (* pop_stack)();
    int (* push_stack)(TOKEN_t);
    int (*empty_stack)(void);
} FUNC_STACK_t;


BEGIN_DEC
static char get_char(TOKEN_t token);
static int print_token(TOKEN_t token);
static int cmp(TOKEN_t token, int values);
static TOKEN_t find_char(char chr);
static TOKEN_t top_stack(void);
static TOKEN_t pop_stack(void);
static int push_stack(TOKEN_t token);
static int empty_stack(void);
END_DEC


static ALL_t g_all =
{
    .arr = {'(', ')', '+', '-', '*', '/', '%', '>', '<'},
    .sinpri = {0, 19, 12, 12, 13, 13, 13, 9, 9,},
    .soutpri = {20, 19, 12, 12, 13, 13, 13, 9, 9,},
    .get_char = get_char,
#define get_char_f g_all.get_char
    .print_token = print_token,
#define print_token_f g_all.print_token
    .cmp = cmp,
#define cmp_f g_all.cmp
    .find_char = find_char,
#define find_char_f g_all.find_char
};

static FUNC_STACK_t stack =
{
    .head = NULL,
#define stack_head stack.head
    .top_stack = top_stack,
#define top_stack_f stack.top_stack
    .pop_stack = pop_stack,
#define pop_stack_f stack.pop_stack
    .push_stack = push_stack,
#define push_stack_f stack.push_stack
    .empty_stack = empty_stack,
#define empty_stack_f stack.empty_stack
};


static TOKEN_t
get_token_f(int *symbol)
{
    int chr;
    TOKEN_t token;
    
    while (isspace(chr = getchar()));
    
    if (isdigit(chr))
    {
        *symbol = chr - '0';
        while (isdigit(chr = getchar()))
        {
            *symbol = 10 * *symbol + (chr - '0');
        }
        
        if (chr != EOF)
        {
            ungetc(chr, stdin);
        }
        
        return operant;
    }
    else if ((token = find_char_f(chr)) != BAD_TAG)
    {
        return token;
    }
  
    return eol;
}

static char
get_char(TOKEN_t token)
{
    if (token >= TAG_MAX)
    {
        return (char)BAD_TAG;
    }
    
    return g_all.arr[token];
}


static int
print_token(TOKEN_t token)
{
    if (token >= TAG_MAX)
    {
        return BAD_TAG;
    }
    
    printf("%c ", get_char_f(token));
    
    return true;
}

static TOKEN_t
find_char(char chr)
{
    int i = 0;
    
    for (i = 0; i < ARR_NUM(g_all.arr); i++)
    {
        if (chr == g_all.arr[i])
        {
            return (TOKEN_t)i;
        }
    }
    
    return BAD_TAG;
}

static int
cmp(TOKEN_t token, int values)
{
    return (g_all.soutpri[token] - g_all.sinpri[values]);
}

static int
empty_stack(void)
{
    return (stack_head == NULL) ? (true) : (false);
}


static TOKEN_t
top_stack(void)
{
    return stack_head->token;
}

static TOKEN_t
pop_stack(void)
{
    TOKEN_t token;
    STACK_t *tmp = stack_head;
    
    stack_head = stack_head->next;
    token = tmp->token;
    
    free(tmp), tmp = NULL;
    
    return token;
}

static int
push_stack(TOKEN_t token)
{
    STACK_t *new = malloc(sizeof(*new));
    if (new == NULL)
    {
        fprintf(stderr, "malloc failure\n");
        return false;
    }
    
    new->token = token;
    new->next = NULL;
    
    new->next = stack_head;
    stack_head = new;
    
    return true;
}


int
mid_to_postfix(void)
{
    int symbol = 0;
    TOKEN_t token;
    
    while ((token = get_token_f(&symbol)) != eol)
    {
        if (token == operant)
        {
            printf("%d ", symbol);
        }
        else if (token == rparen)
        {
            while (top_stack_f() != lparen)
            {
                print_token_f(pop_stack_f());
            }
            pop_stack_f();  // is not shown at left parenthesis
        }
        else
        {
            while (!empty_stack() && cmp_f(token, top_stack_f()) <= 0) // error top_stack_f pop empty
            {
                print_token_f(pop_stack_f());
            }
            push_stack_f(token);
        }
    }
    
    while (empty_stack_f() != true)
    {
        print_token_f(pop_stack_f());
    }
    printf("\n");
    
    return true;
}
