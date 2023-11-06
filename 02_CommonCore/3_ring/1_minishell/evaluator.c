#include "minishell"

void    eval(t_node *node)
{
    switch(node->type)
    {
        case 'Cmdfull':
            if (node->r_child)
                setup_pipex();
            eval(node->l_child);
            if (node->r_child)
                eval(node->r_child);
            break;

        case 'Pipex':
            if (node->r_child)
                setup_pipex();
            eval(node->l_child);
            if (node->r_child)
                eval(node->r_child);
            break;

        case 'Cmd':
            if (node->r_child)
                eval(node->r_child);
            eval(node->l_child);
            break;

        case 'Redirs':
            eval(node->l_child):
            if (node->r_child)
                eval(node->r_child);
            break;

        case 'In':
            setup_in_stream(node);
            break;

        case 'Out':
            if (node->l_child->type == D_out_stream)
                setup_d_out_stream(node);
            else 
                setup_out_stream(node);
            break;

        case 'Call':
            char **args;
            char *cmd;
            if (node->r_child)
                args = setup_args(node->r_child);
            cmd = node->r_child->value;
            exek(cmd, args);

        default:
            err_hdl(ERR_, "trouble at node evaluation");
            break;
    }
}
