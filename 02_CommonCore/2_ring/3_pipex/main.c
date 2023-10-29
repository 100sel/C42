#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <wait.h>

#define ERR_ 1

void err_hdl(int err_num, char *err_msg)
{
    printf("%s\n", err_msg);
    exit(err_num);
}

int main(int argc, char **argv)
{

    if (argc < 5)
        err_hdl(ERR_, "Error <infile cmd1 cmd2 outfile>");
    int pipex[2];
    int a_pid;
    int b_pid;

    if (pipe(pipex) == -1)
        err_hdl(ERR_, "Error with da pipe opening");

    a_pid = fork();
    if (a_pid == -1)
        err_hdl(ERR_, "Error forkin' 1");

    if (!a_pid)
    {
        close(pipex[0]);

        dup2(pipex[1], STDOUT_FILENO);
        close(pipex[1]);

        printf("exec %s\n", argv[2]);
//        perror("exec");
//        err_hdl(ERR_, "Error with 1st cmd");
    }

    if (a_pid)
        b_pid = fork();
    if (b_pid == -1)
        err_hdl(ERR_, "Error forkin' 2");
    
    if (!b_pid)
    {
        close(pipex[1]);

        dup2(pipex[0], STDIN_FILENO);
        close(pipex[0]);

        printf("exec %s\n", argv[3]);
//        perror("exec");
//        err_hdl(ERR_, "Error with 2nd cmd");
    }

    close(pipex[0]);
    close(pipex[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}
