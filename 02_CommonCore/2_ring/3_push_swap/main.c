#include "push_swap.h"

int     main(int argc, char **argv)
{
    t_stack stacks;
    int size;

    if (argc != 2)
        return 1;

    size = strlen(argv[1]);

    stacks.a_stk = get_stack(argv[1], size);
    stacks.b_stk = calloc(sizeof(int), size + 1);

    print_stks(&stacks);
    do_op(&stacks, 1);
    print_stks(&stacks);
    do_op(&stacks, 2);
    print_stks(&stacks);
    do_op(&stacks, 3);
    print_stks(&stacks);

    return 0;
}

void    do_op(t_stack *stacks, int op)
{
    switch(op)
    {
        case 1:
            sa(stacks);
            break;
        case 2:
            sb(stacks);
            break;
        case 3:
            ss(stacks);
            break;
        default:
            break;
    }
}

void    sa(t_stack *stacks)
{
    int tmp;

    tmp     = stacks->a_stk[0];
    stacks->a_stk[0]  = stacks->a_stk[1];
    stacks->a_stk[1]  = tmp;
}

void    sb(t_stack *stacks)
{
    int tmp;

    tmp     = stacks->b_stk[0];
    stacks->b_stk[0]  = stacks->b_stk[1];
    stacks->b_stk[1]  = tmp;
}

void    ss(t_stack *stacks)
{
    sa(stacks);
    sb(stacks);
}

int     *get_stack(char *list, int size)
{
    char *lst_ptr = list;
    int *stk;
    int *stk_ptr;
    char tmp[11] = {0};
    char *tmp_ptr = tmp;
    int n_cnt = 0;

    stk = malloc(sizeof(int) * size + 1);
    stk[size + 1] = '\0';
    stk_ptr = stk;

    for (int i = 0; i < size; i++)
    {
        if (*lst_ptr == ' ')
            lst_ptr++;

        while (*lst_ptr != ' ' && *lst_ptr)
            *tmp_ptr++ = *lst_ptr++;

        *stk_ptr++ = atoi(tmp);
        n_cnt++;
        for (int i = 0; i < 11; i++)
            tmp[i] = 0;
        tmp_ptr = tmp;
    }

    return stk;
}

void    print_stk(int *stk)
{
    while(*stk)
        printf("%d\n", *stk++);
    printf("\n\n");
}

void    print_stks(t_stack *stacks)
{
    printf("STACK A:\n");
    print_stk(stacks->a_stk);
    printf("STACK B:\n");
    print_stk(stacks->b_stk);
}


