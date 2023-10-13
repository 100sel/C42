#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    int i;
    
    i = 0;

    while (i < (int)n)  
        if (*((unsigned char *)(s + i++)) == c)
            return (unsigned char *)(s + (i - 1));

    return 0;
}