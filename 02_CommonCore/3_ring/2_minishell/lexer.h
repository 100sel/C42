#ifndef LEXER_H_
#define LEXER_H_

#define ERR_HDL(...) \
    do { \
        printf("%s: %d: UNREACHABLE: %s \n", __FILE__, __LINE__, __VA_ARGS__); \
        exit(1); \
    } while (0)

#define UNUSED(x) (void)(x)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

typedef enum {
    TOKEN_EOF = 0,
    TOKEN_INVALID,
    TOKEN_UTIL,
    TOKEN_STRING,
    TOKEN_PATH,
    TOKEN_ENV,
    TOKEN_EXIT_STATUS,
    TOKEN_SEMICOLON = ';',
    TOKEN_REDIR_IN = '<',
    TOKEN_REDIR_OUT = '>',
    TOKEN_PIPE = '|',
}       t_token;

typedef struct {
    t_token     type;
    const char  *text;
    size_t      text_len;
}       s_token;

const char  *token_get_type(t_token token_type);
const int   *token_get_hash();

typedef struct {
    const char  *content;
    size_t      content_len;
    size_t      cursor;
    const int   *symbols;
}       s_lexer;

s_lexer lexer_new(const char *content, size_t content_len);
s_token lexer_next(s_lexer *l);
void    lexer_trim(s_lexer *l);

#endif // LEXER_H_
