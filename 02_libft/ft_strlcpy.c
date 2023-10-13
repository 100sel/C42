#include "libft.h"

size_t ft_strlcpy(char *dest, const char *src, size_t n)
{
    int     i;
    i = 0;
    while (i < (int)n)
    {
        dest[i] = src[i];
        i++;
    }
    return i;
}