#include "philosophers.h"

int get_time(void)
{
    t_tval start;

    gettimeofday(&start, NULL);
    return ((int)(start.tv_usec));
}


