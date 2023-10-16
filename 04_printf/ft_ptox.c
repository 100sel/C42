#include "libft.h"

char *ft_ptox(void *ptr)
{
    unsigned char *byte_ptr = (unsigned char *)&ptr;
    char *ret;
    char *buffer;

    ret    = malloc(17);
    buffer = ret;

    for (int j = sizeof(void *) - 1; j >= 0; j--)
    {
        unsigned char byte = byte_ptr[j];
        *buffer++ = "0123456789abcdef"[(byte >> 4) & 0x0F];
        *buffer++ = "0123456789abcdef"[(byte & 0x0F)];
    }
    *buffer = '\0';

    return ret;
}