#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char   *dest_ptr;
    unsigned char   *src_ptr;
    int             i;

    dest_ptr    = (unsigned char *)dest;
    src_ptr     = (unsigned char *)src;
    i           = 0;

    while (i < (int)n)
    {
        dest_ptr[i] = src_ptr[i];
        i++;
    }

    return dest;
}