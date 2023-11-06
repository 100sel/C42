#include "minishell.h"

int     has_next_tkn(const t_iter_tkn itr)
{
    if (itr->type == NULL_END)
        return (0);
    return (1);
}

t_token peek_tkn(const t_iter_tkn itr)
{
    return *itr;
}

t_type_tkn peek_next_tkn(const t_iter_tkn itr)
{
    return  (itr + 1)->type;
}

t_token next_tkn(t_iter_tkn *itr)
{
    t_token    next;
    
    next = **itr;
    (*itr)++;
    return next;
}
