/*
** base macro infomation
*/

#ifndef     __BASEMACRO_H__
#define     __BASEMACRO_H__


/*******************************************************************
 *                          macro                                  *
 *******************************************************************/

//#define DEBUG           

#define WC_PRIVATE_API //module internal interface
#define WC_PUBLIC_API  //module extern interface

#define NUL                     '\0'

#ifndef false
#define false                   (0)
#endif //false

#ifndef true
#define true                    (1)
#endif //true

#define CONSTANT_32             (0x20)
#define CONSTANT_64             (0x40)
#define CONSTANT_128            (0x80)
#define CONSTANT_256            (0x100)
#define CONSTANT_512            (0x200)
#define CONSTANT_1024           (0x400)
#define CONSTANT_2048           (0x800)
#define CONSTANT_4096           (0x1000)

#define WC_CHECK_O1Ptr(ptr)                                     \
    do {                                                        \
        if (ptr == NULL)                                        \
        {                                                       \
            fprintf(stderr, "parameter is NULL\n");             \
            return WC_INVALID_PARAM;                            \
        }                                                       \
    } while (0)


#define WC_CHECK_T2Ptr(ptr1, ptr2)                              \
    do {                                                        \
        if ((ptr1 == NULL) || (ptr2 == NULL))                   \
        {                                                       \
            fprintf(stderr, "p1 = %p, p2 = %p\n", ptr1, ptr2);  \
            return WC_INVALID_PARAM;                            \
        }                                                       \
    } while (0)


#endif //__BASEMACRO_H__
