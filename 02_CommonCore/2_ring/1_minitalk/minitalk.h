#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_digit(char *pid);
int is_print(char *str);
void sendchar(char c, int pid);
int getb(char c, int i);
void sigusr_hdl(int sig, siginfo_t *info, void *ucontext);
