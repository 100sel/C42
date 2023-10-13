#include <unistd.h>
#include <stdio.h>

int ft_char_is_lowercase(char c) {
    if (c > 96 && c < 123) {
        return 1;
    }
    return 0;
}

int ft_char_is_uppercase(char c) {
    if (c > 64 && c < 91) {
        return 1;
    }
    return 0;
}

int ft_char_is_alpha(char c) {
    if (ft_char_is_lowercase(c) || ft_char_is_uppercase(c)) {
        return 1;
    }
    return 0;
}

int ft_char_is_numeric(char c) {
    if (c > 47 && c < 58) {
        return 1;
    }
    return 0;
}

int ft_char_is_noprint(char c) {
    if (c >= 0 && c < 32) {
        return 1;
    }
    return 0;
}

int     ft_str_is_alpha(char *str) {
    int     i;

    i = 0;

    while(str[i] != *("\0")) {
        if (!ft_char_is_alpha(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int     ft_str_is_numeric(char *str) {
    int     i;
    
    i   = 0;
    while (str[i] != *("\0")) {
        if (!ft_char_is_numeric(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int     ft_str_is_lowercase(char *str) {
    int     i;
    
    i   = 0;
    while (str[i] != *("\0")) {
        if (!ft_char_is_lowercase(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int     ft_str_is_uppercase(char *str) {
    int     i;
    
    i   = 0;
    while (str[i] != *("\0")) {
        if (!ft_char_is_uppercase(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int     ft_str_is_printable(char *str) {
    int     i;

    i   = 0;
    
    while (str[i] != *("\0")) {
        if (ft_char_is_noprint(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

char    *ft_strcapitalize(char *str) {
    int     i;

    i   = 0;

    while (str[i] != *("\0")) {
        if ((i == 0 || 
        (!ft_char_is_alpha(str[i - 1]) && 
        !ft_char_is_numeric(str[i - 1])) 
        ) && 
        ft_char_is_lowercase(str[i])) {
            str[i] = str[i] - 32;
        }
        i++;
    }

    return str;
}

unsigned int    ft_strlcpy(char *dest, char *src, unsigned int size) {
    int     i;
    i   = 0;
    while (i < size && src[i] != 0) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return i;
}

void    main() {

}