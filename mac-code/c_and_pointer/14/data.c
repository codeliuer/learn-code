#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	DEBUG			(0)

/*
** #if constant-expression
**			statements
** #endif //statements
** constant-expression(常量表达式)由预处理器进行求值。如果
** 它的值是非零值(真)，那么statements部分就被正常编译，否则
** 预处理器就安静地删除它们.
**
** contant-expression(常量表达式)由预处理器
*/
int
main(int argc, char* argv[])
{
#if DEBUG
	int x = 10;
	printf("x= %d\n", x);
#endif	//DEBUG

	return EXIT_SUCCESS;
}
