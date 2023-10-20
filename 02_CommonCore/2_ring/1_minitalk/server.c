#include "minitalk.h"

int main(void)
{
    printf("%d\n", getpid());

    struct sigaction sa;
    sa.sa_handler = &server_handler;
    sigaction(SIGUSR1, &sa);
    while (1)
    {
    }
    return 0;
}