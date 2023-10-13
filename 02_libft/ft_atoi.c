#include "libft.h"

int power(int n, int p)
{
    int k;
    int ret;
    k   = 0;
    ret = 1;
    while (k++ < p)
        ret *= n;
    return ret;    
};

int ft_atoi(const char *s)
{
    int size;
    int res;
    int i;
    int j;

    size    = ft_strlen(s);
    res     = 0;
    i       = 0;
    j       = size;

    while (i <= size)
        res += (int)(s[i]) * (power(10, j));
    
    return res;
}