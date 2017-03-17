#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define M           (10)
#define N           (8)


int arr[M][N] = {
    {1, 0, 0, 0, 0, 0, 0, 0,},
    {1, 1, 1, 1, 1, 0, 1, 0,},
    {0, 1, 1, 0, 0, 1, 0, 1,},
    {0, 1, 0, 0, 1, 1, 1, 0,},
    {1, 1, 1, 0, 0, 0, 0, 0,},
    {0, 1, 1, 1, 1, 0, 1, 0,},
    {1, 1, 0, 1, 0, 1, 0, 1,},
    {0, 1, 0, 1, 1, 0, 1, 0,},
    {1, 1, 1, 1, 0, 1, 1, 1,},
    {0, 0, 1, 0, 0, 1, 0, 1,},
};

struct INDEX
{
    int x;
    int y;
};

static struct INDEX stack[M*N] = {0};
static int top = -1;


static void push(int x, int y);
static struct INDEX *pop(void);
static void show(void);

static int path(void)
{
    int i = 0;
    int j = 0;
    struct INDEX *tmp = {0};

    if (arr[0][0] != 1 || arr[M-1][N-1] != 1)
    {
        return -1;
    }

    while ((i != N-1) && (j != M-1))
    {
        if (arr[i][j] == 1)
        {
            if (i-1 >= 0 && arr[i-1][j] == 1)
            {
                push(i, j);
                arr[i][j] = 0;
                printf("i = %d, j = %d\n", i, j);

                i -= 1;
            }
            else if (j+1 < M && arr[i][j+1] == 1)
            {
                push(i, j);
                arr[i][j] = 0;
                printf("i = %d, j = %d\n", i, j);

                j += 1;
            }
            else if (i+1 < N && arr[i+1][j] == 1)
            {
                push(i, j);
                arr[i][j] = 0;
                printf("i = %d, j = %d\n", i, j);

                i += 1;
            }
            else if (j-1 >= 0 && arr[i][j-1] == 1)
            {
                push(i, j);
                arr[i][j] = 0;
                printf("i = %d, j = %d\n", i, j);

                j -= 1;
            }
            else
            {
                tmp = pop();
                if (tmp == NULL)
                {
                    return -1;
                }

                i = tmp->x;
                j = tmp->y;
                arr[i][j] = 1;
            }
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    int ret = path();
    if (ret == 0)
    {
        show();
    }
    else
    {
        printf("fail\n");
    }

    return EXIT_SUCCESS;
}

static void push(int x, int y)
{
    int i = ++top;

    stack[i].x = x;
    stack[i].y = y;
}

static struct INDEX *pop(void)
{
    return &stack[top--];
}

static void show(void)
{
    int i = 0;

    for (i = 0; i <= top; i++)
    {
        printf("(%d, %d) ", stack[i].x, stack[i].y);
    }
    printf("\n");
}
