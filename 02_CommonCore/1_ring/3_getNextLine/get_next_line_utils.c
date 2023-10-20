#include "get_next_line.h"

char *make_newl(char *output, char *input, char *out_ptr)
{
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        *out_ptr++ = input[i];
        input[i] = '\0';
        if (*(out_ptr - 1) == '\n' || *(out_ptr - 1) == '\0')
        {
            *out_ptr = '\0';
            prep(input, i + 1);
            return output;
        }
    }
    return output;
}

char *search_flag(char *input)
{
    for (int i = 0; i < BUFFER_SIZE; i++)
        if (input[i] == '\n')
            return input + i;
    return NULL;
}

char *get_last(char *input)
{
    char *ret = NULL;
    for (int i = 0; i < BUFFER_SIZE; i++)
        if (input[i])
            ret = input + i;
    return ret;
}

void prep(char *input, int flag)
{
    char *in_ptr;
    char *ret_ptr;
    in_ptr = input + flag;
    ret_ptr = input;

    while (!*ret_ptr && *in_ptr)
    {
        *ret_ptr++ = *in_ptr;
        *in_ptr++ = '\0';
    }
}

char *bigger_out(char *output, int passage_cnt)
{
    char *cpy;
    int curr_size;
    int next_size;

    curr_size = BUFFER_SIZE * passage_cnt;
    next_size = BUFFER_SIZE * ++passage_cnt;
    cpy = malloc(curr_size);

    for (int i = 0; i < curr_size; i++)
        cpy[i] = output[i];

    free(output);
    output = malloc(next_size);

    for (int i = 0; i < curr_size; i++)
        output[i] = cpy[i];
    
    free(cpy);
    return output;
}



