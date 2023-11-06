typedef enum    e_type_tkn {
    WORD,
    FLAG,
    PIPEX,
    ENV_VAR,
    END_OF_LINE,
    SIMPLE_QUOTE,
    DOUBLE_QUOTE,
    IN_STREAM,
    OUT_STREAM,
    D_OUT_STREAM,
    NULL_END
}               t_type_tkn;

typedef struct  s_slice {
    char    *start;
    int     length;
}               t_slice;

typedef struct  s_token {
    t_type_tkn  type;
    t_slice slice;
}               t_token;

typedef char    *t_iter_char;

int     has_next_char(const t_iter_char itr);
char    peek_char(const t_iter_char itr);
char    next_char(t_iter_char *itr);

t_token get_token(t_iter_char *itr);
t_token *lexer(char *input);
void    print_token(t_token *tkn);

t_token get_word_tkn(t_iter_char *itr);
t_token get_flag_tkn(t_iter_char *itr);
t_token get_ope_tkn(t_iter_char *itr);
t_token get_io_tkn(t_iter_char *itr);
t_token get_quote_tkn(t_iter_char *itr);
t_token get_null_tkn(void);

