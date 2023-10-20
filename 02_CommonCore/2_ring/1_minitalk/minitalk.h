#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void server_handler(int sig)
{
    printf("%s\n", "bitch");
}