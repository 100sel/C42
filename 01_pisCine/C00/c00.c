#include <unistd.h>

void    ft_putchar(char c) {
    write(1, &c, 1);
}

void    ft_print_alphabet(void) {
    char    start;
    char    end;
    int     i;

    start   = *("a");
    end     = *("z");
    i       = start;

    while (i != end) {
        write(1, &i, 1);
        i++;
    }
    write(1, &i, 1);
}

void    ft_print_reverse_alphabet(void) {
    char    start;
    char    end;
    int     i;

    start   = *("z");
    end     = *("a");
    i       = start;

    while (i != end) {
        write(1, &i, 1);
        i--;
    }
    write(1, &i, 1);
}

void    ft_print_numbers(void) {
    char    start;
    char    end;
    int     i;

    start   = *("0");
    end     = *("9");
    i   = start;

    while (i != end) {
        write(1, &i, 1);
        i++;
    }
    write(1, &i, 1);
}

void    ft_is_negative(int n) {
    if (n < 0) {
        write(1, "N", 1);
    } else {
        write (1, "P", 1);
    }
}

void    main() {
}