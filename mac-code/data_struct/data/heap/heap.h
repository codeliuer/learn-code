/***********************************************
 * huffmantree
 ***********************************************/

#ifndef __HUFFMAN_TREE_H__
#define __HUFFMAN_TREE_H__


#define HEAP_SUCC       (0)
#define HEAP_FAIL       (1)


#define HEAP_VOLUME     (100)


typedef int (*CMP_t)(const void *, const void *);


extern int push(void *node, CMP_t cmp);
extern void *pop(CMP_t cmp);


#endif //__HUFFMAN_TREE_H__
