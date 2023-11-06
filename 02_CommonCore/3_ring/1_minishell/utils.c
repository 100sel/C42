#include "minishell.h"

void    err_hdl(int err_num, char *err_msg)
{
    printf("Error %d: %s\n", err_num, err_msg);
    exit(err_num);
}

void    cleaner(t_token *tokens, t_node *nodes)
{
    free(tokens);
    clean_node(nodes);
}

void    clean_node(t_node *node)
{
    if (node->l_child)
        clean_node(node->l_child);
    if (node->r_child)
        clean_node(node->r_child);
    if (node->value)
        free(node->value);
    free(node);
}


