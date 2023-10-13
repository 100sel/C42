#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int     ss1;
    int     ss2;
    int     i;

    i   = 0;
    ss1 = 0;
    ss2 = 0;

    while (i < (int)n)
    {
        ss1 += (int)(s1[i]);
        ss2 += (int)(s2[i]);
        i++;
    } 

    if (ss1 > ss2)
        return 1;
    if (ss1 < ss2)
        return -1;
    return 0;
}