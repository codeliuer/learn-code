#ifndef		__SQLEXT_H__
#define		__SQLEXT_H__


#include "sql.h"


struct TEST
{
	void (*FP_test)(void);
	void (*FP_tt)(void);
};


#define	API_test			api->FP_test
#define	API_tt				api->FP_tt


#endif	//__SQLEXT_H__
