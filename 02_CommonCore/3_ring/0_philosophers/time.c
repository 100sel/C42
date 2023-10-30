#include "philosophers.h"

int get_time(void)
{
    t_tval start;

    gettimeofday(&start, NULL);
    return ((int)(start.tv_usec));
}

int get_time_passed(int start)
{
    int curr_t;

    curr_t = get_time();
    return (curr_t - start);
}

