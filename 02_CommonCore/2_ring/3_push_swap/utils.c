#include "push_swap.h"

void    print_stks(t_set *stacks)
{
    char tmp_a[11] = {0};
    char tmp_b[11] = {0};
    char *tptr;

    printf("\n");
    for (int i = stacks->max_size - 1; i >= 0; i--)
    {
        if (!stacks->a_stk->items[i])
            tmp_a[0] = ' ';
        else 
            sprintf(tmp_a, "%d", stacks->a_stk->items[i]);

        if (!stacks->b_stk->items[i])
            tmp_b[0] = ' ';
        else 
            sprintf(tmp_b, "%d", stacks->b_stk->items[i]);

        printf("%s\t%s\n", tmp_a, tmp_b);

        tptr = tmp_a;
        while (*tptr)
            *tptr++ = '\0';
        
        tptr = tmp_b;
        while (*tptr)
            *tptr++ = '\0';
    }
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
    for (int i = stk->top - 1; i > 0; i--) {
        if (stk->items[i] < stk->items[i - 1]) {
            return 0;
        }
    }
    return 1;
}
