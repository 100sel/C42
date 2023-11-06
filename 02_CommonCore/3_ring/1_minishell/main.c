#include "minishell.h"

int main(void)
{
    char    PATH[MAX_SIZE];
    char    cmd[MAX_SIZE] = {0};
    t_token *tokens;
    t_node  *nodes;

    getcwd(PATH, MAX_SIZE);
//    while (1)
//    {
        printf("minishell$: ");
        fflush(NULL);
        read(0, cmd, MAX_SIZE);
        tokens  = lexer(cmd);
        nodes   = parser(tokens);
        print_node(nodes);
        fflush(NULL);
        memset(cmd, '\0', MAX_SIZE);
        cleaner(tokens, nodes);
//    }
    return (0);
}
