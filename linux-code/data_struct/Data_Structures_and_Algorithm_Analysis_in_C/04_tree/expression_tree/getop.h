/*
** parsing a string
*/

#ifndef     __GETOP_H__
#define     __GETOP_H__


typedef enum OP_t
{
    DATA,
#define DATA            DATA
    OPERATOR,
#define OPERATOR        OPERATOR
    ALPHABET,           
#define ALPHABET        ALPHABET
    OTHER,
#define OTHER           OTHER
} OP_t;


extern OP_t getop(int *pdata);


#endif  //__GETOP_H__
