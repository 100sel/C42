#include "minishell.h"

t_node  *parse_cmdline(t_iter_tkn *itr)
{
    t_node *node;
    
    node = make_node(Cmdline);
    node->l_child = parse_cmdfull(itr);
    node->r_child = make_nodetkn(peek_tkn(*itr));
    return (node);
}

t_node *parse_cmdfull(t_iter_tkn *itr)
{
    t_node *node;

    node = make_node(Cmdfull);
    node->l_child = parse_cmd(itr);
    if (peek_tkn(*itr).type == PIPEX)
        node->r_child = parse_pipex(itr);
    return node;
}

t_node *parse_cmd(t_iter_tkn *itr)
{
    t_node *node;
    
    node = make_node(Cmd);
    if (peek_next_tkn(*itr) == IN_STREAM)
        node->r_child = parse_redirs(itr);
    node->l_child = parse_call(itr);
    if (peek_tkn(*itr).type == OUT_STREAM || peek_tkn(*itr).type == D_OUT_STREAM)
    {
        if (node->r_child)
            node->r_child->r_child = parse_out(itr);
        else
            node->r_child = parse_redirs(itr);
    }
    return node;
}

t_node *parse_pipex(t_iter_tkn *itr)
{
    t_node *node;

    node = make_node(Pipex);
    next_tkn(itr);
    node->l_child = parse_cmd(itr);
    if (peek_tkn(*itr).type == PIPEX)
        node->r_child = parse_pipex(itr);
    return node;
}

t_node *parse_call(t_iter_tkn *itr)
{
    t_node *node;
    
    node = make_node(Call);
    node->l_child = make_nodetkn(peek_tkn(*itr));
    next_tkn(itr);
    if (peek_tkn(*itr).type == FLAG || peek_tkn(*itr).type == WORD || peek_tkn(*itr).type == ENV_VAR)
        node->r_child = parse_args(itr);
    return node;
}

t_node *parse_args(t_iter_tkn *itr)
{
    t_node *node;
    
    node = make_node(Args);
    node->l_child = parse_arg(itr);
    if (peek_tkn(*itr).type == FLAG || peek_tkn(*itr).type == WORD || peek_tkn(*itr).type == ENV_VAR)
        node->r_child = parse_args(itr);
    return node;
}

t_node *parse_arg(t_iter_tkn *itr)
{
    t_node *node;

    if (peek_tkn(*itr).type == ENV_VAR)
    {
        node            = make_node(Arg);
        node->l_child   = make_nodetkn(peek_tkn(*itr));
        next_tkn(itr);
        node->r_child   = make_nodetkn(peek_tkn(*itr));
        next_tkn(itr);
    }
    else if (peek_tkn(*itr).type == FLAG)
    {
        node            = make_node(Arg);
        node->l_child   = make_nodetkn(peek_tkn(*itr));
        next_tkn(itr);
        node->r_child   = make_nodetkn(peek_tkn(*itr));
        next_tkn(itr);
    }
    else if (peek_tkn(*itr).type == WORD)
    {
        node            = make_node(Arg);     
        node->l_child   = make_nodetkn(peek_tkn(*itr));
        next_tkn(itr);
    }
    return node;
}

t_node *parse_redirs(t_iter_tkn *itr)
{
    t_node *node;

    node = make_node(Redirs);
    if (peek_next_tkn(*itr) == IN_STREAM)
        node->l_child = parse_in(itr);
    else
        node->l_child = parse_out(itr);
    return node;
}

t_node *parse_in(t_iter_tkn *itr)
{
    t_node *node;

    node = make_node(In);
    node->r_child = make_nodetkn(peek_tkn(*itr));
    next_tkn(itr);
    node->l_child = make_nodetkn(peek_tkn(*itr));
    next_tkn(itr);
    return node;
}

t_node *parse_out(t_iter_tkn *itr)
{
    t_node *node;

    node = make_node(Out);
    node->l_child = make_nodetkn(peek_tkn(*itr));
    next_tkn(itr);
    node->r_child = make_nodetkn(peek_tkn(*itr));
    next_tkn(itr);
    return node;
}
