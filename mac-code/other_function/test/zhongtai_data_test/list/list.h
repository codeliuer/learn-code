/*
** list operator interface 
*/

#ifndef     __LIST_H__
#define     __LIST_H__


enum 
{
    NAME_F,
#define NAME_F              (0)
    AGE_F,
#define AGR_F               (1)
    MAX_F,
};

#define  LIST_DATA_SUCCESS  (0)
#define  LIST_DATA_PARAM    (1)
#define  LIST_DATA_EXIST    (2)
#define  LIST_DATA_NO_EXIST (3)


typedef struct PERSON PERSON;


extern int insert_info(PERSON **pphead, char *name, int arg);

extern int  delete_info(
    PERSON **pphead, 
    void *data, 
    int type        //NAME_F: name  AGE_F: age 
);

extern int print_info(PERSON *phead);


#endif //__LIST_H__
