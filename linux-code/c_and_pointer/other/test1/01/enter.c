/********************************************************************************
 * from start to end 
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define infinite        for (;;)


#define enter_start(s)      enter(s, "enter start digit = ")
#define enter_end(e)        enter(e, "enter end digit = ")


static void clear(void)
{
    // clear stdin
    scanf("%*[^\n]");
    scanf("%*c");
}

static void enter(int *data, const char *state)
{
    while ((printf("%s", state), scanf("%d", data)) != 1)
    {
        clear();
    }

    clear();
}

static void test_overflow(int front, int sum, int data)
{
    if (((data > 0) && (sum < front)) || ((data < 0) && (sum > front)))
    {
        printf("int overflow\n");
        exit(EXIT_FAILURE);
    }
}

static int start_to_end_add(int start, int end)
{
    int sum = 0;
    int front = 0;

    while (start <= end)
    {
        front = sum;
        sum += start;

        // overflow check
        test_overflow(front, sum, start);

        start += 1;
    }

    return sum;
}

static void test(void)
{
    int start = 0;
    int end = 0;
    int sum = 0;

    enter_start(&start);
    enter_end(&end);

    sum += start_to_end_add(start, end);

    printf("sum = %d\n", sum);
}


int main(int argc, char *argv[])
{
    infinite
    {
        test();
    }

    return EXIT_SUCCESS;
}
