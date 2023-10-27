#include "push_swap.h"

int     main(int argc, char **argv)
{
    if (argc < 2)
        return ERR_;

    t_set   *stacks = init_set(argc - 1, argv);
    int     sorted  = issorted(stacks->a_stk);

    while (!sorted)
    {
        
        sorted = issorted(stacks->a_stk);
    }

    cleaner(stacks);

    return 0;
}

