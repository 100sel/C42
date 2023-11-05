typedef enum    e_type_node {
    CMDLINE, 
    CMDFULL, 
    CMD,
    CALL, 
    ARGS,
    ARG,
    REDIR,
    IN,
    OUT
}               t_type_node;

typedef struct      s_node {
    t_type_node     type;
    char            *value;
    struct s_node   *l_child;
    struct s_node   *r_child;
}                   t_node;

typedef t_token *t_iter_tkn;

int     has_next_tkn(const t_iter_tkn itr);
t_token peek_tkn(const t_iter_tkn itr);
t_token next_tkn(t_iter_tkn *itr);

t_node  *parser(t_token *tokens);
void    print_node(t_node *node);

t_node  *make_node(t_type_node type);
void    add_child(t_node *parent, t_node *child);
t_node  *made_word(char *value);

t_node  *parse_cmdline(t_token *tokens);
t_node  *parse_cmdfull(t_token *tokens);
t_node  *parse_cmd(t_token *tokens);
t_node  *parse_call(t_token *tokens);
t_node  *parse_args(t_token *tokens);
t_node  *parse_arg(t_token *tokens);
t_node  *parse_redir(t_token *tokens);
t_node  *parse_in(t_token *tokens);
t_node  *parse_out(t_token *tokens);
