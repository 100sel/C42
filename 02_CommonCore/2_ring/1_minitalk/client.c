#include "minitalk.h"

int is_digit(char *pid)
{
    char *ptr;
    ptr = pid;

    while (*ptr)
        if (!isdigit(*ptr++))
                return 0;

    return 1;
}

int is_print(char *str)
{
    char *ptr;
    ptr = str;

    while (*ptr)
        if (!isprint(*ptr++))
                return 0;

    return 1;
}

void sendchar(char c, int pid)
{
    for (int i = 0; i < 8; i++)
    {
        int bvalue = getb(c, i);

        if (!bvalue)
        {
            if (kill(pid, SIGUSR1) == -1)
            {
                perror("kill");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            if(kill(pid, SIGUSR2) == -1)
            {
                perror("kill");
                exit(EXIT_FAILURE);
            }
        }
        usleep(500);
    }
} 

int getb(char c, int i)
{
    int bvalue = (c >> (8 - 1 - i)) & 1;
    return bvalue; 
}

int main(int argc, char **argv)
{
    if (argc != 3)
        return 1;

    if (!is_digit(argv[1]))
        return 1;

    if (!is_print(argv[2]) || strlen(argv[2]) > 256)
        return 1;

    int pid = atoi(argv[1]);
    char *str = argv[2];

    for (int i = 0; i < (int)strlen(str); i++)
        sendchar(str[i], pid); 
    sendchar('\0', pid); 

    usleep(1000);

	return 0;
}
