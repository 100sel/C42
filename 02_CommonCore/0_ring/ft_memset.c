#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char   *ptr;
    int             i;

    ptr = s;
    i   = 0;
    while (i < (int)n)
        ptr[i++] =  (unsigned char)c;
    return s;
}