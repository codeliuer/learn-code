#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BASE_DATA		(10)
#define MAX_RANGE		(10)
#define print_msg		printf("Enter multiplier: ")


typedef unsigned long long	u64int_t;
typedef unsigned int		u32int_t;

static void clear_stdin_buffer(void)
{
	scanf("%*[^\n]");
	scanf("%*c");
}

static void enter_mul(u32int_t *ptr)
{
	for (print_msg; scanf("%u", ptr) != 1; print_msg)
	{
		printf("Enter invalid\n");

		clear_stdin_buffer();
	}
}

#define free_buffer(array)		{free(array); array = NULL;}

static u32int_t get_zero(unsigned int max)
{
	u32int_t n = 0;

	while (max /= BASE_DATA)
	{
		n += 1;
	}

	return n;
}

static u32int_t to_space(u32int_t x)
{
    u32int_t a = 1;
    u32int_t sum = 0;
    u32int_t base = 9;  // 0 - 9 (1) | 10-99 (2) | 100-999 (3) ...
    u32int_t other = 1;

    while (x / BASE_DATA)
    {
        sum += base * a;
        a += 1;
        base *= BASE_DATA;
        other *= BASE_DATA;

        x /= BASE_DATA;
    }

    sum += ((x-1) * other + 1) * a;

    return sum;
}

static u32int_t get_space(u32int_t mul)
{
    u32int_t x = 0;
    u32int_t sum = 0;
    u32int_t base = BASE_DATA;

    while (mul > 0)
    {
        x = mul % base;
        sum += to_space(x);
        mul -= x;
        base *= BASE_DATA;
    }

    return sum;
}

static u32int_t *get_buffer(u32int_t mul)
{
	u32int_t bits = get_zero(mul);

	u32int_t *array = (u32int_t *)malloc(( get_space(mul) * 4 )/bits+1);

	if (array == NULL)
	{
		perror("malloc:");
		exit(EXIT_FAILURE);
	}

	return array;
}

static void calculate(u32int_t *array, u32int_t mul)
{
	u32int_t n = 0;
	u32int_t i = 0, j = 0, m = 0;
	u64int_t bigdigit = 0, mod = 0;

	m = 0, array[m] = (1<mul) ? 1 : 0;
	for (i = 2; i <= mul; i++)
	{
		bigdigit = 0, mod = 0;

		for (j = 0; j <= m; j++)
		{
			bigdigit = array[j] * i + mod;
			array[j] = bigdigit % MAX_RANGE;
			mod = bigdigit / MAX_RANGE;
		}

		while (mod > 0)
		{
			array[++m] = mod % MAX_RANGE;
			mod /= MAX_RANGE;
		}
	}

	n = get_zero(MAX_RANGE);

	printf("%d", array[m]);
	while (m--)
	{
		printf("%0*d", n, array[m]);
	}
	printf("\n");
}

static void factorial(u32int_t mul)
{
	u32int_t *array = get_buffer(mul);

	calculate(array, mul);

	free_buffer(array);
}

int main(int argc, char *argv[])
{
	u32int_t mul = 0;

	enter_mul(&mul);
	
	factorial(mul);

	return EXIT_SUCCESS;
}
