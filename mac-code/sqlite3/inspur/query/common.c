/*
** implemantation
*/

#include "common.h"

#include "src.h"
#include "mid.h"
#include "dst.h"


void
init(void)
{
	src_init();
	dst_init();
	mid_init();
}


void
exec(void)
{
	src_exec();
}


void 
uninit(void)
{
	src_uninit();
	dst_uninit();
	mid_uninit();
}
