#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#include <unistd.h>
#include <pthread.h>
#include <bits/local_lim.h>


static void *make_space(void)
{
    void *stack = (void *)malloc(PTHREAD_STACK_MIN);
    assert(stack);

    return stack;
}


static void destroy_space(void *stack)
{
    free(stack);
}


static void create_thread(void)
{
}


int main(int argc, char *argv[])
{
    void *stack = make_space();

    create_thread(stack);

    destroy_space(stack);

    return EXIT_SUCCESS;
}
