#include "libft.h"

void *ft_calloc(size_t nelem, size_t elsize)
{
    size_t  st;
    int     i;
    void    *p;

    st  = nelem * elsize;
    i   = 0;
    p = malloc(st);

    while (i < (int)nelem)
        *((char *)(p + i++)) = 0;

    return p;
}