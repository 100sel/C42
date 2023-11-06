#include "minishell.h"

int     has_next_char(const t_iter_char itr)
{
    if (*itr == '\n' || *itr == '\0')
        return (0);
    return (1);
}

char    peek_char(const t_iter_char itr)
{
    return *itr;
}

char    next_char(t_iter_char *itr)
{
    char    next;
    
    next = **itr;
    (*itr)++;
    return next;
}
