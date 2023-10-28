#include "push_swap.h"

void    do_op(int op, t_set *set) 
{
    switch(op)
    {
        case SA:
            sx(set->a_stk);
            printf("sa\n");
            break;
        case SB:
            sx(set->b_stk);
            printf("sb\n");
            break;
        case SS:
            ss(set);
            printf("ss\n");
            break;
        case PA:
            px(set->a_stk, set->b_stk);
            printf("pa\n");
            break;
        case PB:
            px(set->b_stk, set->a_stk);
            printf("pb\n");
            break;
        case RA:
            rx(set->a_stk);
            printf("ra\n");
            break;
        case RB:
            rx(set->b_stk);
            printf("rb\n");
            break;
        case RR:
            rr(set);
            printf("rr\n");
            break;      
        case RRA:
            rrx(set->a_stk);
            printf("rra\n");
            break;
        case RRB:
            rrx(set->b_stk);
            printf("rrb\n");
            break;
        case RRR:
            rrr(set);
            printf("rrr\n");
            break;      


        default:
            break;
    }
}

void    sx(t_stack *stk)
{
    t_node tmp;

    tmp                       = stk->items[stk->top - 1];
    stk->items[stk->top - 1]  = stk->items[ + stk->top - 2];
    stk->items[stk->top - 2]  = tmp;
}

void    ss(t_set *set)
{
    sx(set->a_stk);
    sx(set->b_stk);
}

void    px(t_stack *dest, t_stack *src)
{
    dest->items[dest->top]   = src->items[src->top - 1];
    memset((src->items) + (src->top - 1), 0, sizeof(t_node));
    dest->top++;
    src->top--;
}

void    rx(t_stack *stk)
{
    t_node tmp;

    tmp = stk->items[stk->top - 1];

    for (int i = stk->top - 1; i > 0; i--)
        stk->items[i] = stk->items[i - 1];

    stk->items[0] = tmp;
}

void    rr(t_set *set)
{
    rx(set->a_stk);
    rx(set->b_stk);
}

void    rrx(t_stack *stk)
{
    t_node tmp;

    tmp = stk->items[0];

    for (int i = 0; i < stk->top - 1; i++)
        stk->items[i] = stk->items[i + 1];

    stk->items[stk->top - 1] = tmp;
}

void    rrr(t_set *set)
{
    rrx(set->a_stk);
    rrx(set->b_stk);
}
