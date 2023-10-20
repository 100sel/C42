#include "minitalk.h"

char *str = "TESTING BITCH\n";

void sigusr1_hdl(int sig)
{
	if (*str)
		write(1, str, strlen(str));
}

int main(void)
{
    printf("%d\n", getpid());

    struct sigaction sa;
    sa.sa_handler = &sigusr1_hdl;
    sigaction(SIGUSR1, &sa, NULL);
    
    pause();

    return 0;
}
