#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t n)
{
    if (n <= ft_strlen(dest) + 1)
        return ft_strlen(dest) + ft_strlen(src);

    int     i;
    int     j;

    i = 0;
    j = 0;

    while (dest[i])
        i++;

    while (i < (int)n - 1 && src[i])
        dest[i++] = src[j++];

    dest[i] = 0;
    return ft_strlen(dest) + ft_strlen(src);
}