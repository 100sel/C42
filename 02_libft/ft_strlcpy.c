#include "libft.h"

size_t ft_strlcpy(char *dest, const char *src, size_t n)
{
    if ((int)n == 0)
        return ft_strlen(src);

    int     i;
    i = 0;
    while (i < (int)n - 1 && src[i])
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = 0;

    return ft_strlen(src);
}