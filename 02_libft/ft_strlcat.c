#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t n)
{
    int     i;
    int     j;

    i = ft_strlen(dest);
    j = 0;

    while (i < (int)n)
        dest[i++] = src[j++];

    dest[i] = 0;
    return ft_strlen(dest) + ft_strlen(src);
}