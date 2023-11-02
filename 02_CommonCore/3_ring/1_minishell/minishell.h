#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE    256 

typedef enum    e_type {
    COMMAND,
    EXECUTABLE,
    ARGUMENT,
    END_OF_LINE,
    SIMPLE_QUOTE,
    DOUBLE_QUOTE,
    IN_STREAM,
    OUT_STREAM,
    D_OUT_STREAM,
    PIPEX,
    ENV_VAR
}               t_type;

typedef struct  s_token {
    t_type  type;
    char    *value;
}               t_token;


