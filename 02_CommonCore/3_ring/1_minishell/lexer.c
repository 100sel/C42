#include "minishell.h"

t_token get_token(t_iter_char *itr)
{
    char c;

    c = peek_char(*itr);
    if (isalpha(c))
        return get_word_tkn(itr);
    if (c == ';' || c == '|' || c == '$' || c == '-')
        return get_ope_tkn(itr);
    if (c == '<' || c == '>')
        return get_io_tkn(itr);
    if (c == '\'' || c == '\"')
        return get_quote_tkn(itr);
    err_hdl(ERR_, "trouble with value of *iter at get_token()");
    return get_null_tkn();
}

t_token *lexer(char *input)
{
    t_token *tokens;
    t_token *tokens_ptr;
    t_iter_char  input_itr;

    tokens      = calloc(MAX_SIZE, sizeof(t_token));
    if (!tokens)
    {
        err_hdl(ERR_, "trouble when allocating memory to tokens** at lexer()");
        return NULL;
    }
    tokens_ptr  = tokens;
    input_itr   = input; 
    while (has_next_char(input_itr))
    {
        if (peek_char(input_itr) == ' ')
        {
            next_char(&input_itr);
            continue;
        }
        *tokens_ptr++ = get_token(&input_itr);
    }
    *tokens_ptr = get_null_tkn();
    return (tokens);
}

void    print_token(t_token *tkn)
{
    int     i;
    int     size;
    int     type;
    char    *value;
    t_slice slice;

    i       = 0;
    type    = (int)(tkn->type);
    slice   = tkn->slice;
    size    = slice.length;
    value   = slice.start;
    printf("Type %d: ", type);
    while (i < size)
        printf("%c", value[i++]);
    printf("\n");
    fflush(NULL);
}
