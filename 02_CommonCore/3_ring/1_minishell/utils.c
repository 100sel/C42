#include "minishell.h"

void    err_hdl(int err_num, char *err_msg)
{
    printf("Error %d: %s\n", err_num, err_msg);
    exit(err_num);
}
