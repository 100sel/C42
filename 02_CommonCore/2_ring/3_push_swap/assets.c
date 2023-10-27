#include "push_swap.h"

t_set   *init_set(int size, char **list)
{
    t_set   *stks;
    t_stack *a_stk;
    t_stack *b_stk;

    stks            = malloc(sizeof(t_set));
    a_stk           = malloc(sizeof(t_stack));
    b_stk           = malloc(sizeof(t_stack));

    a_stk->items    = init_stack(size, list);
    b_stk->items    = calloc(sizeof(int), size);

    stks->max_size  = size;
    a_stk->top      = size;
    b_stk->top      = 0;

    stks->a_stk     = a_stk;
    stks->b_stk     = b_stk;

    return stks;
}

int     *init_stack(int size, char **list)
{
    t_node  *stk;
    t_node  *ptr;
    char    *dptr;
    int     tmp;

    stk = malloc(sizeof(t_node) * size);
    ptr = stk;

    for (int i = size; i > 0; i--)
    {
        dptr = list[i];
        while (*dptr)
            if (!isdigit(*dptr++))
                    err_hdl(ERR_, "Can't do other than int");

        tmp     = atoi(list[i]);

        if (!tmp)
            err_hdl(ERR_, "Can't be 0");

        for (int j = 0; j < size; j++)
            if (tmp == stk[j])
                err_hdl(ERR_, "Can't have duplicate");

        *ptr++->value  = tmp;
    }

    return stk;
}

int     *get_nvalue(t_stack *stk)
{
    t_node *tmp[stk->top - 1];

    for (int i = 0; i < top - 1; i++)
        tmp[i] = stk + i;

    qsort(tmp, stk->top - 1, sizeof(t_node), cmp);

    for (int i = 
}

