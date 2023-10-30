#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>

typedef struct timeval t_tval;
typedef pthread_t t_thread;
typedef pthread_mutex_t t_mutex;

typedef struct  s_phil {
    int         num;
    int         num_of_phil;
    int         time_to_die;
    int         time_to_eat;
    int         time_to_sleep;
    int         last_meal;
    t_thread    *thread;
    t_mutex     *fork_l;
    t_mutex     *fork_r;
}               t_phil;


int     get_time(void);
int     get_time_passed(int start);

void    do_sleep(int phil_num, int time_to_sleep);
void    do_think(int phil_num, int time_to_die, int last_meal);
void    do_eat(int phil_num, t_mutex *fork_r, t_mutex *fork_l, int time_to_eat);

void    *routine(void *obj);
t_phil  *make_phil(t_mutex *forks, int index, char **argv);
