#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int     ft_strlen(char *str) {
    int     i;
    i   = 0;
    while (str[i] != 0) {
        i++;
    }
    return i;
}

char    *ft_strdup(char *src) {
    int     src_size;
    char    *result;
    int     i;

    src_size    = ft_strlen(src);
    result      = malloc(src_size * 1);
    i           = 0;

    while(src[i] != 0) {
        result[i] = src[i];
        i++;
    }

    result[i] = 0;
    return result;
}

int     *ft_range(int min, int max) {
    int     i;
    int     *r;
    int     s;

    s = max - min;
    r = malloc(s * sizeof(int));
    i = 0;

    while (i < s) {
        r[i] = min;
        min++;
        i++;
    } 

    r[i] = 0;
    return r;
}

char    *ft_strjoin(int size, char **strs, char *sep) {
    char     *r;

    if (size == 0) {
        r = malloc(sizeof(char));
        *r = 0;
        return r;
    }

    int     i;
    int     j;
    int     k;
    char    b[100];

    i   = 0;
    j   = 0;
    k   = 0;

    while (i < size) {
        while (strs[i][k] != 0) {
            b[j] = strs[i][k];
            j++;
            k++;
        }
        k = 0;
        while (sep[k] != 0 && i != size - 1) {
            b[j] = sep[k];
            j++;
            k++;
        }
        i++;
        k = 0;
    }
    b[j] = 0;

    r = malloc(j * 1);

    i = 0;
    while (i <= j) {
        r[i] = b[i];
        i++;
    }

    return r;
}

void    main() {

}