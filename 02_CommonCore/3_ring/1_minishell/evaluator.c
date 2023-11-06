#include "minishell.h"

void    eval(t_node *node)
{
    switch(node->type)
    {
        case Cmdfull:
            if (node->r_child)
                set_pipex();
            eval(node->l_child);
            if (node->r_child)
                eval(node->r_child);
            break;

        case Pipex:
            if (node->r_child)
                set_pipex();
            eval(node->l_child);
            if (node->r_child)
                eval(node->r_child);
            break;

        case Cmd:
            if (node->r_child)
                eval(node->r_child);
            eval(node->l_child);
            break;

        case Redirs:
            eval(node->l_child);
            if (node->r_child)
                eval(node->r_child);
            break;

        case In:
            set_in(node);
            break;

        case Out:
            if (node->l_child->type == D_out_stream)
                set_d_out(node);
            else 
                set_out(node);
            break;

        case Call:
            char **args;
            char *cmd;
            if (node->r_child)
                args = set_args(node->r_child);
            cmd = node->r_child->value;
            exek(cmd, args);
            break;

        default:
            err_hdl(ERR_, "trouble at node evaluation");
            break;
    }
}
