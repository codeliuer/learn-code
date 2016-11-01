#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define QUEUE_HIGH			(5)


#define SUCCESS				(1)
#define FAILURE				(0)
#define NOT_SUPPORT			(-1)


typedef struct QUEUE_t
{
	void *		stack[QUEUE_HIGH];
	int			top;
} QUEUE_t;


#define A					(0)
#define B					(1)

static QUEUE_t queue[] =
		{
#define stack_a		queue[0]
			{{NULL}, -1,},
#define stack_b		queue[1]
			{{NULL}, -1,},
		};


static int 
stack_full(int type)
{
	if (type == A)
	{
		return stack_a.top+1 == QUEUE_HIGH; 
	}
	else if (type == B)
	{
		return stack_b.top+1 == QUEUE_HIGH; 
	}

	return NOT_SUPPORT;
}


static int 
stack_empty(int type)
{
	if (type == A)
	{
		return stack_a.top == -1;
	}
	else if (type == B)
	{
		return stack_b.top == -1;
	}

	return NOT_SUPPORT;
}


static int 
stack_push(void *pdata, int type)
{
	if (type == A)
	{
		if (stack_full(A) != SUCCESS)
		{
			stack_a.stack[++stack_a.top] = pdata;

			return SUCCESS;
		}

		return FAILURE;
	}
	else if (type == B)
	{
		if (stack_full(B) != SUCCESS)
		{
			stack_b.stack[++stack_b.top] = pdata;

			return SUCCESS;
		}

		return FAILURE;
	}

	return NOT_SUPPORT; 
}


static int 
stack_pop(void **pdata, int type)
{
	if (type == A)
	{
		if (stack_empty(A) != SUCCESS)
		{
			*pdata = stack_a.stack[stack_a.top--];

			return SUCCESS;
		}

		return FAILURE;
	}
	else if (type == B)
	{
		if (stack_empty(B) != SUCCESS)
		{
			*pdata = stack_b.stack[stack_b.top--];

			return SUCCESS;
		}

		return FAILURE;
	}

	return NOT_SUPPORT;
}


static int 
stack_flush(void)
{
	int i = stack_a.top;

	if (stack_empty(B) != SUCCESS)
	{
		return FAILURE;
	}

	while (i-- >= 0)
	{
		stack_b.stack[--stack_b.top] = stack_a.stack[stack_a.top--];
	}

	return SUCCESS;
}


int 
queue_push(void *pdata)
{
	if (stack_full(A) != SUCCESS)
	{
		printf("line: = %d, data = %d\n", __LINE__, (int)pdata);
		stack_push(pdata, A);

		return SUCCESS;
	}
	else
	{
		if (stack_flush() == SUCCESS)
		{
			stack_push(pdata, A);

			return SUCCESS;
		}

		return FAILURE;
	}
}


int 
queue_pop(void **ppdata)
{
	if (stack_empty(B) == SUCCESS)
	{
		printf("stack flush\n");
		stack_flush();

		if (stack_empty(B) == SUCCESS)
		{
			return FAILURE;
		}
	}

	printf("stack pop\n");
	return stack_pop(ppdata, B);
}


int
main(int argc, char * argv[])
{
	void *ppdata;

	void *pdata[] = 
		{
			(void *)1, (void *)2, (void *)3, (void *)4, (void *)5,
		};

	queue_push(pdata[0]);
	queue_push(pdata[1]);
	queue_push(pdata[2]);
	queue_push(pdata[3]);
	queue_push(pdata[4]);
	
	queue_pop(&ppdata);
	printf("%d\n", (int)ppdata);
	queue_pop(&ppdata);
	printf("%d\n", (int)ppdata);
	queue_pop(&ppdata);
	printf("%d\n", (int)ppdata);
	queue_pop(&ppdata);
	printf("%d\n", (int)ppdata);
	queue_pop(&ppdata);
	printf("%d\n", (int)ppdata);

	return EXIT_SUCCESS;
}
