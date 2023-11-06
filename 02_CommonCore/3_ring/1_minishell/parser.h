typedef enum    e_type_node {
    Word, 
    Flag,
    Pipex,
    Env_var,
    End_of_line,
    Simple_quote,
    Double_quote,
    In_stream,
    Out_stream,
    D_out_stream,
    Null_end,
    Cmdline, 
    Cmdfull, 
    Cmd,
    Call, 
    Args,
    Arg,
    Redirs,
    In,
    Out,
    COUNT_
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
t_type_tkn peek_next_tkn(const t_iter_tkn itr);
t_token next_tkn(t_iter_tkn *itr);

t_node  *parser(t_token *tokens);
void    print_node(t_node *node);
char    *get_type(t_type_node type);

t_node  *make_node(t_type_node type);
t_node  *make_nodetkn(t_token token);

t_node  *parse_cmdline(t_iter_tkn *itr);
t_node  *parse_cmdfull(t_iter_tkn *itr);
t_node  *parse_cmd(t_iter_tkn *itr);
t_node  *parse_pipex(t_iter_tkn *itr);
t_node  *parse_call(t_iter_tkn *itr);
t_node  *parse_args(t_iter_tkn *itr);
t_node  *parse_arg(t_iter_tkn *itr);
t_node  *parse_redirs(t_iter_tkn *itr);
t_node  *parse_in(t_iter_tkn *itr);
t_node  *parse_out(t_iter_tkn *itr);
