#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <wait.h>

#define ERR_        1
#define MAX_ARGS    8
#define MAX_CHAR    16

void err_hdl(int err_num, char *err_msg)
{
    printf("%s\n", err_msg);
    exit(err_num);
}

char *parse_path(char *cmd)
{
    char *path = "/usr/bin/";
    char *path_ptr = path;
    char *cmd_ptr = cmd;
    int size_path = (int)strlen(path);
    int size_cmd = (int)strlen(cmd);
    int size_t = size_path + size_cmd;
    char *fp = malloc(size_t + 1);
    int i = 0;;

    while (i < size_path)
        fp[i++] = *path_ptr++;

    while (i < size_t)
        fp[i++] = *cmd_ptr++;

    fp[i] = '\0';

    return fp;
}

char **split_cmd(char *cmd)
{
    char    **args          = calloc(MAX_ARGS, sizeof(char));
    char    **args_ptr      = args;
    char    tmp[MAX_CHAR]   = {'\0'};
    char    *tmp_ptr        = tmp;
    int     flag            = 0;
    int     next            = 1;
    int     size            = (int)strlen(cmd);

    for (int i = 0; i < size; i++)
    {
        if (cmd[i] != ' ' && !flag && next && i != size - 1)
        {
            flag = 1;
            next = 0;
            *tmp_ptr++ = cmd[i];
            continue;
        }

        if (cmd[i] != ' ' && flag && !next && i != size - 1)
        {
            *tmp_ptr++ = cmd[i];
            continue;
        }

        if (cmd[i] == ' ' || i == size - 1)
        {
            if (i == size - 1)
                *tmp_ptr = cmd[i];

            next = 1;
            flag = 0;
            *args_ptr = calloc(strlen(tmp) + 1, sizeof(char));
            
            for (int j = 0; j < (int)strlen(tmp); j++)
                (*args_ptr)[j] = tmp[j];

            args_ptr++;
            tmp_ptr = tmp;
            memset(tmp, '\0', MAX_CHAR);

            continue;
        }
    }

    return args;
}

int main(int argc, char **argv)
{

    if (argc < 5)
        err_hdl(ERR_, "Error <infile cmd1 cmd2 outfile>");

    int pipex[2];
    int a_pid;
    int b_pid;
    int a_fd;
    int b_fd;
    char **args;
    char *path;

    if (pipe(pipex) == -1)
        err_hdl(ERR_, "Error with da pipe opening");

    a_pid = fork();
    if (a_pid == -1)
        err_hdl(ERR_, "Error forkin' 1");

    if (!a_pid)
    {
        close(pipex[0]);
        a_fd = open(argv[1], O_RDONLY);
        if (a_fd == -1)
            err_hdl(ERR_, "Error with file1");

        args = split_cmd(argv[2]);
        path = parse_path(args[0]);

        dup2(a_fd, STDIN_FILENO);
        dup2(pipex[1], STDOUT_FILENO);
        close(pipex[1]);
        
        execve(path, args, NULL);
        
        perror("exec");
        err_hdl(ERR_, "Error with 1st cmd");
    }

    if (a_pid)
        b_pid = fork();
    if (b_pid == -1)
        err_hdl(ERR_, "Error forkin' 2");
    
    if (!b_pid)
    {
        close(pipex[1]);
        b_fd = (open(argv[4], O_WRONLY));
        if(b_fd == -1)
            err_hdl(ERR_, "Error with file2");

        args = split_cmd(argv[3]);
        path = parse_path(args[0]);

        dup2(pipex[0], STDIN_FILENO);
        dup2(b_fd, STDOUT_FILENO);
        close(pipex[0]);

        execve(path, args, NULL);
        
        perror("exec");
        err_hdl(ERR_, "Error with 2nd cmd");
    }

    close(pipex[0]);
    close(pipex[1]);
    close(a_fd);
    close(b_fd);

    waitpid(a_pid, NULL, 0);
    waitpid(b_pid, NULL, 0);

    return 0;
}
