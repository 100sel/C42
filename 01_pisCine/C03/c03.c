#include <stdio.h>

int             ft_strncmp(char *s1, char *s2, unsigned int n) {
    int i;
    int j;

    i   = 0;
    j   = 0;

    while (i < n || (s1[j] != 0 && s2[j] != 0)) {
        if (s1[j] > s2[j]) {
            return 1;
        }
        if (s1[j] < s2[j]) {
            return -1;
        }
        i++;
        j++;
    }
    if (s1[j] == 0 && s2[j] == 0) {
        return 0;
    }
    if (s2[j] == 0) {
        return 1;
    }
    if (s1[j] == 0) {
        return -1;
    }
}

char            *ft_strstr(char *str, char *to_find) {
    if (to_find[0] == 0)
        return str; 
    
    int i;
    int j;
    int b;

    i   = 0;
    j   = 0;

    while (str[i] != 0) {
        
        if (str[i] == to_find[j]) {
            b = i;

            while (to_find[j] != 0) {

                if (str[i] != to_find[j]) {
                    i = b + 1;
                    j = 0;
                    break;
                }

                i++;
                j++;
            }
            
            if (to_find[j] == 0) {
                return str + b;
            }
 
       }

        i++;
    }

    return "\0";
}   

unsigned int     ft_strlcat(char *dst, char *src, unsigned int size) {
    int i;
    int j;

    i   = 0;
    j   = 0;

    while (dst[i] != 0) 
        i++;
    
    while (i < size) {
        if (src[j] == 0)
            break;
        dst[i] = src[j];
        i++;
        j++;
    }
    dst[i] = 0;
}

int main() {
    
}