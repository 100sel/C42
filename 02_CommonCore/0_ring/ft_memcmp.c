#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    int i;
    int ss1;
    int ss2;

    i   = 0;
    ss1 = 0;
    ss2 = 0;

    while (i < (int)n)
    {
        ss1 += (int)(*(unsigned char *)(s1 + i));
        ss2 += (int)(*(unsigned char *)(s2 + i));
        i++;
    }

    if (ss1 > ss2)
        return 1;
    if (ss1 < ss2)
        return -1;
    return 0;
}