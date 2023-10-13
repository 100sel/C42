#include <stdio.h>
#include <unistd.h>

void    ft_ft(int *nbr){
    *nbr = 42;
}

void    ft_swap(int *a, int *b) {
    int     buffer;

    buffer = *b;
    *b = *a;
    *a = buffer;
}

void    ft_div_mod(int a, int b, int *div, int *mod) {
    *div    = a / b;
    *mod    = a % b;
}

void    ft_putstr(char *str) {
    int     i;

    i   = 0;
    while (str[i] != *("\0")) {
        write(1, str + i, 1);
        i++;
    }
}

int    ft_strlen(char *str) {
    int     i;

    i   = 0;
    while (str[i] != *("\0")) {
        i++;
    }
    return i;
}

void    main() {

}