#include "lexer.h"
#include "parser.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE    256 
#define ERR_        1

void    err_hdl(int err_num, char *err_msg);
