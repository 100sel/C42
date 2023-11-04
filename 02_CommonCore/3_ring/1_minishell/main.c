#include "minishell.h"

int main(void)
{
    char    PATH[MAX_SIZE];
    char    cmd[MAX_SIZE] = {0};
    t_token *tokens;

    getcwd(PATH, MAX_SIZE);
    while (1)
    {
        printf("minishell$: ");
        fflush(NULL);
        read(0, cmd, MAX_SIZE);
        tokens = lexer(cmd);
        while (tokens->type != NULL_END)
            print_token(tokens++);
        fflush(NULL);
        memset(cmd, '\0', MAX_SIZE);
    }
    return (0);
}
