#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define N           (6)


#define RANGE_MIN   (0)
#define RANGE_MAX   (5)


static int 
range_data(void)
{
    return rand()%(RANGE_MAX-RANGE_MIN) + RANGE_MIN;
}


static void 
init_array(int (* arr)[6], int n)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 6; j++)
        {
            arr[i][j] = range_data();
        }
    }
}


static void
print_array(int (* arr)[6], int n)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }
}


#define MAX(a, b)       ((a) > (b) ? (a) : (b))


static int
parse_data(int (* arr)[6], int n)
{
    int (* max)[6] = malloc(n*sizeof(*max));

    int i = 0;
    int j = 0;
    int sum = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if (i == 0 && j == 0)
            {
                max[i][j] = arr[0][0];
            }
            else if (i == 0)
            {
                max[i][j] = arr[i][j] + max[i][j-1];
            }
            else if (j == 0)
            {
                max[i][j] = arr[i][j] + max[i-1][j];
            }
            else
            {
                max[i][j] = MAX(max[i-1][j], max[i][j-1])+arr[i][j];
            }
        }
    }

    sum = max[n-1][5];

    free(max), max = NULL;

    return sum;
}


int
main(int argc, char *argv[])
{
    int arr[N][N] = {0};

    srand(time(NULL));
    init_array(arr, N);

    printf("max total = %d\n", parse_data(arr, N));

    print_array(arr, N);

    return EXIT_SUCCESS;
}
