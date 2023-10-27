#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct  s_stack {
    int     *a_stk;
    int     *b_stk;
}               t_stack;

void    sa(t_stack *stacks);
void    sb(t_stack *stacks);
void    ss(t_stack *stacks);

void    do_op(t_stack *stacks, int op);

int     *get_stack(char *list, int size);

void    print_stk(int *stk);
void    print_stks(t_stack *stacks);
