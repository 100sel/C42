#include "push_swap.h"

int     main(int argc, char **argv)
{
    if (argc < 2)
        return ERR_;

    t_set   *stacks = init_set(argc - 1, argv);

    print_stks(stacks);

    int max_num = stacks->max_size;
    int max_bits = 0;

    while (max_num >> max_bits != 0) 
        max_bits++;

    for (int i = 0; i < max_bits; i++)
    {
        for (int j = 0; j < stacks->max_size; j++)
        {
            if ((stacks->a_stk->items[stacks->a_stk->top - 1].nval >> i) & 1)
                do_op(RA, stacks);
            else
                do_op(PB, stacks);
           // print_stks(stacks);
        }
        while (stacks->b_stk->top)
            do_op(PA,stacks);
    }

    print_stks(stacks);
    cleaner(stacks);

    return 0;
}

