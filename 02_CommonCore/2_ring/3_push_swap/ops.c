#include "push_swap.h"

void    do_op(int op, t_set *stacks) 
{
    switch(op)
    {
        case SA:
            sx(stacks->a_stk);
            printf("sa\n");
            break;
        case SB:
            sx(stacks->b_stk);
            printf("sb\n");
            break;
        case SS:
            ss(stacks);
            printf("ss\n");
            break;
        case PA:
            px(stacks->a_stk, stacks->b_stk);
            printf("pa\n");
            break;
        case PB:
            px(stacks->b_stk, stacks->a_stk);
            printf("pb\n");
            break;
        case RA:
            rx(stacks->a_stk);
            printf("ra\n");
            break;
        case RB:
            rx(stacks->b_stk);
            printf("rb\n");
            break;
        case RR:
            rr(stacks);
            printf("rr\n");
            break;      
        case RRA:
            rrx(stacks->a_stk);
            printf("rra\n");
            break;
        case RRB:
            rrx(stacks->b_stk);
            printf("rrb\n");
            break;
        case RRR:
            rrr(stacks);
            printf("rrr\n");
            break;      


        default:
            break;
    }
}

void    sx(t_stack *stk)
{
    int tmp;

    tmp                 = stk->items[stk->top - 1];
    stk->items[stk->top - 1]     = stk->items[stk->top - 2];
    stk->items[stk->top - 2] = tmp;
}

void    ss(t_set *stacks)
{
    sx(stacks->a_stk);
    sx(stacks->b_stk);
}

void    px(t_stack *dest, t_stack *src)
{
    dest->items[dest->top]  = src->items[src->top - 1];
    src->items[src->top - 1]    = 0;
    dest->top++;
    src->top--;
}

void    rx(t_stack *stk)
{
    int tmp;

    tmp = stk->items[stk->top - 1];

    for (int i = stk->top - 1; i > 0; i--)
        stk->items[i] = stk->items[i - 1];

    stk->items[0] = tmp;
}

void    rr(t_set *stacks)
{
    rx(stacks->a_stk);
    rx(stacks->b_stk);
}

void    rrx(t_stack *stk)
{
    int tmp;

    tmp = stk->items[0];

    for (int i = 0; i < stk->top - 1; i++)
        stk->items[i] = stk->items[i + 1];

    stk->items[stk->top - 1] = tmp;
}

void    rrr(t_set *stacks)
{
    rrx(stacks->a_stk);
    rrx(stacks->b_stk);
}
