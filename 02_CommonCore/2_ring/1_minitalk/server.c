#include "minitalk.h"

int BIT_VALUE = -1;

void sigusr_hdl(int sig)//, siginfo_t *info, void *ucontext)
{
    if (sig == SIGUSR1)
        BIT_VALUE = 0;
    else 
        BIT_VALUE = 1;
}

int main(void)
{
    char *str;
    char *str_ptr;
    char byte;
    int bit_cnt;

    str = malloc(256);
    memset(str, 0, 256);
    str_ptr = str;
    byte = 0;
    bit_cnt = 0;

    printf("%d\n", getpid());

    struct sigaction sa;
    sa.sa_handler = &sigusr_hdl;
    sa.sa_flags = 0;//SA_SIGINFO;

    //sigemptyset(&sa.sa_mask);
    //sigaddset(&sa.sa_mask, SIGUSR1);
    //sigaddset(&sa.sa_mask, SIGUSR2);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
    {
        if (bit_cnt > 7)
        {
            if (!byte)
            {
                write(1, str, strlen(str));
                write(1, "\n", 1);

                bit_cnt = 0;
                free(str);
                str = malloc(256);
                memset(str, 0, 256);
                str_ptr = str;

                continue;
            }

            *str_ptr++ = byte;

            byte = 0;
            bit_cnt = 0;
        }

        pause();


        if (!BIT_VALUE) 
        {
            byte = byte & ~(1 << (8 - 1 - bit_cnt));
        }
        else 
        {
            byte = byte | (1 << (8 - 1 - bit_cnt));
        }
        bit_cnt++;
    }

    free(str);

    return 0;
}
