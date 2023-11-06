#include "minishell.h"

t_node  *parser(t_token *tokens)
{
    t_iter_tkn  tokens_itr;
    t_node      *nodes;

    tokens_itr = tokens;
    nodes = parse_cmdline(&tokens_itr);
    return nodes;
}

t_node *make_node(t_type_node type)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    node->type      = type;
    node->value     = NULL;
    node->l_child   = NULL;
    node->r_child   = NULL;
    return node;
}

t_node  *make_nodetkn(t_token token)
{
    t_node  *node;
    t_slice slice;

    node    = make_node((t_type_node)(token.type));
    if (node->type == Null_end)
    {
        node->value = NULL;
        return node;
    }
    slice   = token.slice;
    node->value = calloc(slice.length + 1, sizeof(char));
    for (int i = 0; i < slice.length; i++) 
        node->value[i] = slice.start[i];
    return node;
}

void    print_node(t_node *node)
{
    char    *type;
    char    *value;
    t_node  *l_child;
    t_node  *r_child;

    type    = get_type(node->type);
    value   = node->value;
    l_child = node->l_child;
    r_child = node->r_child;
    printf("Node type %s", type);
    if (value)
        printf(" '%s'\n", value);
    else 
        printf("\n");
    if (!l_child && !r_child)
        printf("leaf\n");
    if (l_child)
    {
        printf("%s Left: ", type);
        print_node(l_child);
    }
    if (r_child)
    {
        printf("%s Right: ", type);
        print_node(r_child);
    }
}

char *get_type(t_type_node type) {
    char *types[] = {
        "Word",
        "Flag",
        "Pipex",
        "Env_var",
        "End_of_line",
        "Simple_quote",
        "Double_quote",
        "In_stream",
        "Out_stream",
        "D_out_stream",
        "Null_end",
        "Cmdline",
        "Cmdfull",
        "Cmd",
        "Call",
        "Args",
        "Arg",
        "Redirs",
        "In",
        "Out"
    };
    if (type >= 0 && type < COUNT_) {
        return types[type];
    } else {
        return "Unknown";
    }
}
