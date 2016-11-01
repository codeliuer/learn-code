#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>


#define NUL			'\0'

#define OUT			(0)
#define IN			(1)

#define UNUSED(x)	((void)(x))

#define infinite	for (;;)


typedef struct POS_t
{
		int row;
		    int col;
} POS_t;


typedef struct ACTION_t
{
	    POS_t head;
		void (* shift)(int, int);
		void (* print)(void);
} ACTION_t;


static void shift_map(int direction, int values);
static void print_map(void);


static ACTION_t action = 
{
	.head = {0, 0},
	.shift = shift_map,
	.print = print_map,
};


void 
shift_map(int direction, int values)
{
	switch (direction)
	{
		case 'A':
			action.head.row -= values;
			break;
		case 'D':
			action.head.row += values;
			break;
		case 'W':
			action.head.col += values;
			break;
		case 'S':
			action.head.col -= values;
			break;
		default:
			printf("invalid value\n");
			break;
	}
}


static void 
print_map(void)
{
	printf("\n%d,%d\n", action.head.row, action.head.col);
}


static char*
self_getbuffer(char *string, int len)
{
	int i = 0;
	int ch;
			    
	UNUSED(len);
				    
	while ((ch = getchar()) != NUL && ch != EOF && ch != ';')
	{
		string[i++] = ch;
	}
					    
	if (i == 0 && (ch == ';' || ch == NUL || ch == EOF))
	{
		return NULL;
	}
						    
	string[i] = NUL;

	return string;
}    

static bool
get_value(char *string, int *tag, int *value)
{
	int num = 0;
		    
	if (*string != 'A' && *string != 'S' && *string != 'D' && *string != 'W')
	{
		return false;
	}
			    
	*tag = *string;
				    
	while (isdigit(*++string))
	{
		num = 10 * num + (*string-'0');
	}

	if (*string != NUL)
	{
		return false;
	}
						    
	*value = num;

	return true;
}

static void 
test(void)
{
	int value = 0;
	int tag = 0;
	char buffer[10] = "";

	while (self_getbuffer(buffer, sizeof(buffer)) != NULL)
	{
		if (get_value(buffer, &tag, &value))
		{
			action.shift(tag, value);
		}
	}

	action.print();
}


int
main(int argc, char *argv[])
{	
	test();
		    
	return EXIT_SUCCESS;
}    
