#include "minishell.h"

int main(void)
{
    char PATH[MAX_SIZE];
    char cmd[MAX_SIZE] = {0};

    getcwd(PATH, MAX_SIZE);
    while (1)
    {
        printf("$: ");
        fflush(NULL);
        read(0, cmd, MAX_SIZE);
        printf("%s", cmd);
        fflush(NULL);
        memset(cmd, '\0', MAX_SIZE);
    }
    return (0);
}

t_token *get_token(char *str)
{
    t_token *token;

    token = malloc(sizeof(t_token));

    return token;
}

t_token **lexer(char *input)
{
    t_token **tokens;
    t_token *token;

    tokens = malloc(sizeof(t_token) * MAX_SIZE);
    
    return tokens;
}

