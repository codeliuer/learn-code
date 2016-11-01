/*
** mid function statement
*/

#ifndef		__DST_H__
#define		__DST_H__

#ifdef __cplusplus
extern "C" {
#endif	//cplusplus


extern void dst_init(void);
extern int dst_exec(int tsId, int serviceId);
extern void dst_uninit(void);


#ifdef __cplusplus
}
#endif	//cplusplus

#endif	//__DST_H__
