#include "push_swap.h"

t_set   *init_set(int size, char **list)
{
    t_set   *set;
    t_stack *a_stk;
    t_stack *b_stk;

    set            = malloc(sizeof(t_set));
    a_stk           = malloc(sizeof(t_stack));
    b_stk           = malloc(sizeof(t_stack));

    a_stk->items    = init_stack(size, list);
    b_stk->items    = calloc(sizeof(t_node), size);

    set->max_size  = size;
    a_stk->top      = size;
    b_stk->top      = 0;

    set->a_stk     = a_stk;
    set->b_stk     = b_stk;

    get_nvalue(a_stk);

    return set;
}

t_node  *init_stack(int size, char **list)
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
            if (tmp == stk[j].value)
                err_hdl(ERR_, "Can't have duplicate");

        ptr++->value  = tmp;
    }

    return stk;
}

void    get_nvalue(t_stack *stk)
{
    int     size = stk->top - 1;
    t_node  *tmp[size];

    for (int i = 0; i <= size; i++)
        tmp[i] = (stk->items) + i;

    qsort(tmp, size + 1, sizeof(t_node *), cmp_nodev);

    for (int i = 0; i <= size; i++)
        tmp[i]->nval = i + 1;
}
