#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char* argv[])
{
	int i = 0;

	/* 
	** 宏使用了大括号表达式，对于大括号表达式，
	** 编译器会展开所有表达式，同时使用最后一个
	** 表达式的结果进行返回。
	*/
	printf("%d\n", ({++i; ++i;}));

	return EXIT_SUCCESS;
}
