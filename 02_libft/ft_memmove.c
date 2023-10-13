#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char   *dest_ptr;
    unsigned char   *src_ptr;
    unsigned char   buffer[n];
    int             i;

    dest_ptr    = (unsigned char *)dest;
    src_ptr     = (unsigned char *)src;
    i           = 0;

    while (i < (int)n)
    {
        buffer[i] = src_ptr[i];
        i++;
    }

    i = 0;

    while (i < (int)n)
    {
        dest_ptr[i] = buffer[i];
        i++;
    }

    return dest;
}