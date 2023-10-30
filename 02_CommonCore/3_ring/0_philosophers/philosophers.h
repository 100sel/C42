#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

typedef struct timeval t_tval;

int     get_time(void);
int     get_time_passed(int start);
