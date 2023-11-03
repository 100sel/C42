#include "minishell.h"

t_token *get_word_tkn(t_iter *itr)
{
    char    c;
    int     length;
    t_slice slice;
    t_token *token;
    
    c               = peek(*itr);
    length          = 0;
    slice.start    = *itr;
    while (c != ' ' && c != '\0' && c != '\n')
    {
        next(itr);
        length++;
        c = peek(*itr);
    }   
    slice.length    = length;
    token           = malloc(sizeof(t_token));
    token->slice    = slice;
    token->type     = WORD;
    return (token);
}

t_token *get_ope_tkn(t_iter *itr)
{
    char    c;
    t_slice slice;
    t_token *token;

    c               = peek(*itr);
    slice.start    = *itr;
    slice.length   = 1;
    token           = malloc(sizeof(t_token));
    token->slice    = slice;
    if (c == ';')
        token->type = END_OF_LINE;
    if (c == '|')
        token->type = PIPEX;
    if (c == '$')
        token->type = ENV_VAR;
    if (c == '-')
        token->type = FLAG;
    next(itr);
    return (token);
}

t_token *get_io_tkn(t_iter *itr)
{
    char    c;
    t_slice slice;
    t_token *token;

    c               = peek(*itr);
    slice.start     = *itr;
    token           = malloc(sizeof(t_token));
    if (c == '<')
    {
        next(itr);
        slice.length   = 1;
        token->type     = IN_STREAM;
    }
    else if (c == '>')
    {
        next(itr);
        c = peek(*itr);
        if (c == '>')
        {
            next(itr);
            slice.length   = 2;
            token->type     = D_OUT_STREAM;
        }
        else
        {
            slice.length   = 1;
            token->type     = OUT_STREAM;
        }
    }
    token->slice = slice;
    return (token);
}

t_token *get_quote_tkn(t_iter *itr)
{
    if (*itr)
        return NULL;
    return NULL;
}
