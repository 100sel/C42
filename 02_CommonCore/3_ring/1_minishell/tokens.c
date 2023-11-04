#include "minishell.h"

t_token get_word_tkn(t_iter_char *itr)
{
    char    c;
    int     length;
    t_slice slice;
    t_token token;
    
    c               = peek_char(*itr);
    length          = 0;
    slice.start    = *itr;
    while (c != ' ' && c != '\0' && c != '\n')
    {
        next_char(itr);
        length++;
        c = peek_char(*itr);
    }   
    slice.length    = length;
    token.slice    = slice;
    token.type     = WORD;
    return (token);
}

t_token get_ope_tkn(t_iter_char *itr)
{
    char    c;
    t_slice slice;
    t_token token;

    c               = peek_char(*itr);
    slice.start    = *itr;
    slice.length   = 1;
    token.slice    = slice;
    if (c == ';')
        token.type = END_OF_LINE;
    if (c == '|')
        token.type = PIPEX;
    if (c == '$')
        token.type = ENV_VAR;
    if (c == '-')
        token.type = FLAG;
    next_char(itr);
    return (token);
}

t_token get_io_tkn(t_iter_char *itr)
{
    char    c;
    t_slice slice;
    t_token token;

    c               = peek_char(*itr);
    slice.start     = *itr;
    if (c == '<')
    {
        next_char(itr);
        slice.length   = 1;
        token.type     = IN_STREAM;
    }
    else if (c == '>')
    {
        next_char(itr);
        c = peek_char(*itr);
        if (c == '>')
        {
            next_char(itr);
            slice.length   = 2;
            token.type     = D_OUT_STREAM;
        }
        else
        {
            slice.length   = 1;
            token.type     = OUT_STREAM;
        }
    }
    token.slice = slice;
    return (token);
}

t_token get_quote_tkn(t_iter_char *itr)
{
    next_char(itr);
    return get_null_tkn();
}

t_token get_null_tkn(void)
{
    t_token tkn;
    t_slice slc;

    slc.start  = NULL;
    slc.length = 0;
    tkn.slice  = slc;
    tkn.type   = NULL_END;
    return(tkn);
}
