#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> 

char *get_next_line(int fd)
{
    char chunks[BUFFER_SIZE];
    char *output;
    char *out_ptr;
    static char input[BUFFER_SIZE + 1];
    char *in_ptr;
    char *flag;
    char *in_check;
    int passage_cnt;
    int chunk_cnt;

    output = malloc(BUFFER_SIZE);
    out_ptr = output;
    flag = NULL;
    passage_cnt = 1;

    while (1)
    {
        chunk_cnt = 0;
        in_ptr = input;
        in_check = get_last(input);

        if (in_check)
        {
            flag = search_flag(input);
            if (flag)
            {
                make_newl(output, input, out_ptr);
                break;
            }
            while(in_ptr != in_check)
            {
                in_ptr++;
                chunk_cnt++;
            }
        }

        if (!read(fd, chunks, BUFFER_SIZE - chunk_cnt))
            return NULL;

        for (int i = 0; i < BUFFER_SIZE - chunk_cnt; i++)
            *in_ptr++ = chunks[i];
        *in_ptr = '\0';

        flag = search_flag(input);

        if (flag)
        {
            make_newl(output, input, out_ptr);
            break;
        }

        make_newl(output, input, out_ptr);

        output = bigger_out(output, passage_cnt);
        out_ptr = output + (BUFFER_SIZE * passage_cnt);
        passage_cnt++;
    }

    return output;
}

int main(void)
{
    char *str;
    int fd;
    fd = open("input.txt", O_RDONLY);
    while ((str = get_next_line(fd)))
    {
        printf("%s", str);
        free(str);
    }
    return 0;
}