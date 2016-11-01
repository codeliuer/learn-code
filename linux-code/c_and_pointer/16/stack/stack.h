#ifndef     __STACK_H__
#define     __STACK_H__


#define MUL_PROCESS     //mul process
#define MUL_THREAD      //mul thread


#define __BEGIN_DECLS       //begin declaration
#define __END_DECLS         //end declaration


#define STACK_ERRCODE_SUCCESS           (0)
#define STACK_ERRCODE_PARAMETER         (1)
#define STACK_ERRCODE_MEMORY            (2)

#define STACK_ERRCODE_UNKNOWN           (0xFF)


typedef void*               STACK_TYPE;
typedef struct STACK_HANDLE STACK_HANDLE;


__BEGIN_DECLS


extern int stack_init(STACK_HANDLE** pphandle);
extern int push(STACK_HANDLE* phandle, STACK_TYPE* values);
extern int pop(STACK_HANDLE* phandle, STACK_TYPE* values);
extern int stack_destroy(STACK_HANDLE* phandle);


__END_DECLS


#endif  //__STACK_H__
