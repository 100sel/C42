#include "minishell.h"

t_token *get_token(t_iter *itr)
{
    char c;

    c = peek(*itr);
    if (isalpha(c))
        return get_word_tkn(itr);
    if (c == ';' || c == '|' || c == '$' || c == '-')
        return get_ope_tkn(itr);
    if (c == '<' || c == '>')
        return get_io_tkn(itr);
    if (c == '\'' || c == '\"')
        return get_quote_tkn(itr);
    err_hdl(ERR_, "trouble with value of *iter at get_token()");
    return NULL;
}

t_token **lexer(char *input)
{
    t_token **tokens;
    t_iter  input_itr;

    tokens      = calloc(MAX_SIZE, sizeof(t_token *));
    if (!tokens)
        err_hdl(ERR_, "trouble when allocating memory to tokens** at lexer()");
    input_itr   = input; 
    while (has_next(input_itr))
    {
        if (peek(input_itr) == ' ')
        {
            next(&input_itr);
            continue;
        }
        *(tokens++) = get_token(&input_itr);
    }
    *tokens = NULL;
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
