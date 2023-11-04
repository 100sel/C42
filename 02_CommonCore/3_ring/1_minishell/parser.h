typedef enum    e_type_node {

}               t_type_node;

typedef struct  s_node {

}               t_node;

typedef t_token *t_iter_char;

int     has_next_tkn(const t_iter_tkn itr);
t_token peek_tkn(const t_iter_tkn itr);
t_token next_tkn(t_iter_tkn *itr);

t_token *parser(t_token *tokens);
void    print_node(t_node *node);
