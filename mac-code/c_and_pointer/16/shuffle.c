#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define	FALSE					(0)
#define	TRUE					(1)

#define	ELENUM(arr)				(sizeof(arr)/sizeof(arr[0]))


#define	SWAP(a, b, t)				\
	do {							\
		t = a;						\
		a = b;						\
		b = t;						\
	} while (0)

static void
shuffle(int* deck, int n_cards)
{
	int i = 0;
	int temp = 0;
	int where = 0;
	static int first_time = TRUE;

	if (first_time == TRUE)
	{
		first_time = FALSE;
		srand((unsigned int)time(NULL));
	}

	for (i = n_cards-1; i > 0; i--)
	{
		where = rand() % i;

		SWAP(deck[i], deck[where], temp);
	}
}

static void
init(int* deck, size_t num)
{
	while (num--)
	{
		deck[num] = num+1;
	}
}

static void
show(int* deck, size_t num)
{
	while (num--)
	{
		printf("%d  ", *deck++);
	}
	printf("\n");
}

int
main(int argc, char* argv[])
{
	int deck[20] = {0};

	init(deck, ELENUM(deck));
	shuffle(deck, ELENUM(deck));
	show(deck, ELENUM(deck));

	return EXIT_SUCCESS;
}
