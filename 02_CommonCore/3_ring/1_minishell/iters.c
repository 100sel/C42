#include "minishell.h"

int     has_next(const t_iter itr)
{
    if (*itr != '\n' && *itr != '\0')
        return (1);
    return (0);
}

char    peek(const t_iter itr)
{
    return *itr;
}

char    next(t_iter *itr)
{
    char    next;
    
    next = **itr;
    (*itr)++;
    return next;
}
