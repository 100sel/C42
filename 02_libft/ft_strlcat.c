#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t n)
{
    int     i;
    int     j;
    int     ret;

    ret = ft_strlen(dest) + ft_strlen(src);
    i = 0;
    j = 0;

    if (n <= ft_strlen(dest) + 1)
        return ret;

    while (dest[i])
        i++;

    while (i < (int)n - 1 && src[j])
        dest[i++] = src[j++];

    dest[i] = 0;
    return ret;
}