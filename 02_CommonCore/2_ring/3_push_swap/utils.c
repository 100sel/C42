#include "push_swap.h"

void    print_stks(t_set *stacks)
{
    printf("\n");
    for (int i = 0; i < stacks->max_size; i++)
        printf("%d\t%d\n", stacks->a_stk->items[i], stacks->b_stk->items[i]);
    printf("-\t-\nA\tB\n\n\n");
}

void    cleaner(t_set *stacks)
{
    free(stacks->a_stk->items);
    free(stacks->b_stk->items);
    free(stacks->a_stk);
    free(stacks->b_stk);
    free(stacks);
}

void    err_hdl(int err_no, char *err_msg)
{
    printf("Error\n%s\n", err_msg);
    exit(err_no);
}

int issorted(t_stack *stk) {
    for (int i = 1; i < stk->top; i++) {
        if (stk->items[i - 1] > stk->items[i]) {
            return 0;
        }
    }
    return 1;
}
