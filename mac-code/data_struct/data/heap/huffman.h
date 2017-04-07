/***********************************************
 * huffmantree
 ***********************************************/

#ifndef __HUFFMAN_TREE_H__
#define __HUFFMAN_TREE_H__


#define HEAP_SUCC       (0)
#define HEAP_FAIL       (1)


typedef struct huffmantree
{
    struct huffmantree      *left;
    struct huffmantree      *right;
    struct huffmantree      *parent;
    int                     weight;
} huffmantree;


extern int push(huffmantree *node);
extern huffmantree *pop(void);


#endif //__HUFFMAN_TREE_H__
