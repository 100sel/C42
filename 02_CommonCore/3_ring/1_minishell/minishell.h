#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE    256 
#define ERR_        1

typedef char *t_iter;

typedef enum    e_type {
    WORD,
    FLAG,
    END_OF_LINE,
    SIMPLE_QUOTE,
    DOUBLE_QUOTE,
    IN_STREAM,
    OUT_STREAM,
    D_OUT_STREAM,
    PIPEX,
    ENV_VAR,
    NULL_END
}               t_type;

typedef struct  s_slice {
    char    *start;
    int     length;
}               t_slice;

typedef struct  s_token {
    t_type  type;
    t_slice slice;
}               t_token;

int     has_next(const t_iter itr);
char    peek(const t_iter itr);
char    next(t_iter *itr);

t_token get_token(t_iter *itr);
t_token *lexer(char *input);
void    print_token(t_token *tkn);

t_token get_word_tkn(t_iter *itr);
t_token get_flag_tkn(t_iter *itr);
t_token get_ope_tkn(t_iter *itr);
t_token get_io_tkn(t_iter *itr);
t_token get_quote_tkn(t_iter *itr);
t_token get_null_tkn(void);

void    err_hdl(int err_num, char *err_msg);
