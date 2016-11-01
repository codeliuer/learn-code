#ifndef     __TREE_H__
#define     __TREE_H__


#define BEGIN_DECLARE           //begin declare
#define END_DECLARE             //end declare


#define TREE_API                //tree operation api


#define TREE_SUCCESS            (0)
#define TREE_FAILURE            (1)
#define TREE_MEMORY             (2)
#define TREE_NOT_EXIST          (3)


typedef int                 TREE_ELE;
typedef struct TREE         TREE;
typedef int (*FP_cmp_t)(const void* v1, const void* v2);


TREE_API int 
insert_node(TREE** pproot, TREE_ELE* ele, FP_cmp_t cmp);
TREE_API int 
search_node(TREE* pproot, TREE_ELE* ele, FP_cmp_t cmp);
TREE_API int 
del_node(TREE** pproot, TREE_ELE* ele, FP_cmp_t cmp);


#endif  //__TREE_H__
