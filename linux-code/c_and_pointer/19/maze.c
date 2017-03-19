#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#define M           (10)
#define N           (13)


int arr[M+2][N+2] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0,},
    {0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0,},
    {0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0,},
    {0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0,},
    {0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0,},
    {0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0,},
    {0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0,},
    {0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0,},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0},
    {0, 0 ,1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
};


typedef struct INDEX
{
    int x;
    int y;
} INDEX;


static INDEX stack[M*N] = {0};
static int top = -1;

static void push(int x, int y)
{
    int i = ++top;

    stack[i].x = x;
    stack[i].y = y;

    printf("(%d, %d)", x, y);
    sleep(1);
}

static INDEX *pop(void)
{
    if (top == -1)
    {
        return NULL;
    }

    return &stack[top--];
}


static void show_path(void)
{
    INDEX *tmp = NULL;

    tmp = pop();
    if (tmp == NULL)
    {
        return;
    }

    show_path();
    //printf("(%d, %d) ", tmp->x, tmp->y);
}

static int maze(void)
{
    int x = 1;
    int y = 1;
    INDEX *tmp = NULL;

    while (x != M || y != N)
    {
        if (arr[x][y-1] != 1 && arr[x-1][y] != 1 
            && arr[x][y+1] != 1 && arr[x+1][y] != 1)
        {
            arr[x][y] = 2;

            if ((tmp = pop()) == NULL)
            {
                return -1;
            }

            x = tmp->x;
            y = tmp->y;
        }

        push(x, y);
        arr[x][y] = 2;
        if (arr[x][y-1] == 1)
        {
            y -= 1;
        }
        else if (arr[x-1][y] == 1)
        {
            x -= 1;
        }
        else if (arr[x][y+1] == 1)
        {
            y += 1;
        }
        else
        {
            x += 1;
        }
    }

    if (arr[M][N] == 1)
    {
        return 0;
    }

    return -1;
}

static void show_chess(void)
{
    int i = 0;
    int j = 0;

    printf("        ");
    for (j = 0; j < N+2; j++)
    {
        printf("%4d", j);
    }
    printf("\n");
    printf("\n");

    for (i = 0; i < M+2; i++)
    {
        printf("%s%-2d", "      ", i);
        for (j = 0; j < N+2; j++)
        {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
}

static void do_signal(int signo)
{
    printf("\n##########################################################\n");
    printf("\n");
    show_chess();
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    signal(SIGINT, do_signal);

    setbuf(stdout, NULL);

    show_chess();

    if (maze() == 0)
    {
        printf("\n");
        //show_path();
        printf("\n");
    }

    printf("\n");

    return EXIT_SUCCESS;
}
