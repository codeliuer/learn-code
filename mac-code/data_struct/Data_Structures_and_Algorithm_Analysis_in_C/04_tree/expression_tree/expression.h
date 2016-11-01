/*
** expression tree implementation
*/


#ifndef     __EXPRESSION_H__
#define     __EXPRESSION_H__


typedef struct EBREE EBREE;

extern void expression_tree(EBREE **root);
extern void print_tree(EBREE *root);


#endif  //__EXPRESSION_H__
