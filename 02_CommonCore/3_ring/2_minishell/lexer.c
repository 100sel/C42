#include "lexer.h"

const int   *token_get_hash(void)
{
    char        symbols[] = {'-', ';', '\'', '\"', '<', '>', '|', '$', '?'}; 
    static int  hashtable[128] = {0};
    int         i = 0;

    while (symbols[i]) {
        hashtable[(int)symbols[i]] = 1;
        i += 1;
    }

    return hashtable;
}

const char  *token_get_type(t_token token_type)
{
    switch(token_type) {
        case TOKEN_EOF:
            return "EOF"; 
        case TOKEN_UTIL:
            return "UTIL";
        case TOKEN_STRING:
            return "STRING";
        case TOKEN_PATH:
            return "PATH";
        case TOKEN_ENV:
            return "ENV";
        case TOKEN_SEMICOLON:
            return "SEMICOLON";
        case TOKEN_REDIR_IN:
            return "REDIR_IN";
        case TOKEN_REDIR_OUT:
            return "REDIR_OUT";
        case TOKEN_PIPE:
            return "PIPE";
        case TOKEN_EXIT_STATUS:
            return "EXIT STATUS";
        case TOKEN_INVALID:
            return "INVALID";
        default: 
            ERR_HDL("UNKNOWN TOKEN TYPE");
    }
}

t_token     token_get_symbol(char token)
{
    switch(token) {
        case ';': 
            return TOKEN_SEMICOLON;
        case '<': 
            return TOKEN_REDIR_IN;
        case '>': 
            return TOKEN_REDIR_OUT;
        case '|': 
            return TOKEN_PIPE;
        default:
            return TOKEN_INVALID;
    }
}

s_lexer     lexer_new(const char *content, size_t content_len)
{
    s_lexer l = {0};
    l.content = content;
    l.content_len = content_len;
    l.symbols = token_get_hash();
    return l;
}

void        lexer_trim(s_lexer *l)
{
    while (l->cursor < l->content_len && isspace(l->content[l->cursor]))
        l->cursor += 1;
}

s_token     lexer_next(s_lexer *l)
{
    lexer_trim(l);

    s_token token = {
        .text = &l->content[l->cursor],
        .text_len = 0,
    };

    if (l->cursor >= l->content_len)
        return token;
 
    if (isalpha(l->content[l->cursor])) {
        while (l->cursor < l->content_len && isalpha(l->content[l->cursor])) {
            l->cursor       += 1;
            token.text_len  += 1;
        }
        token.type = TOKEN_UTIL;
        return token;
    }

    if (l->content[l->cursor] == '\"' || l->content[l->cursor] == '\'') {
        l->cursor       += 1;
        token.text      += 1;

        while (l->cursor < l->content_len && l->content[l->cursor] != '\"' && l->content[l->cursor] != '\'') {
            l->cursor += 1;
            token.text_len += 1;
        }
        l->cursor       += 1;
        token.type      = TOKEN_STRING;

        return token;
    }

    if (l->content[l->cursor] == '.' || l->content[l->cursor] == '/') {
        while (l->cursor < l->content_len && l->content[l->cursor] != ' ') {
            l->cursor       += 1;
            token.text_len  += 1;
        }
        token.type = TOKEN_PATH;

        return token;
    }

    if (l->content[l->cursor] == '$') {

        if (l->content[l->cursor + 1] == '?') {
            l->cursor       += 2;
            token.text_len  += 2;
            token.type = TOKEN_EXIT_STATUS;
            return token;
        }
    
        while (l->cursor < l->content_len && l->content[l->cursor] != ' ') {
            l->cursor       += 1;
            token.text_len  += 1;
        }

        token.type = TOKEN_ENV;
        return token;
    }

    if (l->symbols[(int) l->content[l->cursor]]) {
        token.type = token_get_symbol(l->content[l->cursor]);
        l->cursor += 1;
        token.text_len = 1;
        return token;
    }

    l->cursor += 1;
    token.type = TOKEN_INVALID;
    token.text_len = 1;

    return token;
}
