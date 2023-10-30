#include "philosophers.h"

void do_sleep(int phil_num, int time_to_sleep)
{
    printf("%d %d is sleeping\n", get_time() / 1000, phil_num);
    fflush(NULL);
    usleep(time_to_sleep * 1000);
}

void do_think(int phil_num, int time_to_die, int last_meal)
{
    int time_left;

    time_left = get_time() - last_meal;
    printf("%d %d is thinking\n", get_time() / 1000, phil_num); 
    fflush(NULL);
    usleep(time_left - ((time_to_die * 1000) * 0.1));
}

void do_eat(int phil_num, t_mutex *fork_r, t_mutex *fork_l, int time_to_eat)
{
    pthread_mutex_lock(fork_r);
    printf("%d %d has taken a fork\n", get_time() / 1000, phil_num); 
    fflush(NULL);
    pthread_mutex_lock(fork_l);
    printf("%d %d has taken a fork\n", get_time() / 1000, phil_num); 
    fflush(NULL);
    printf("%d %d is eating\n", get_time() / 1000, phil_num); 
    fflush(NULL);
    usleep(time_to_eat * 1000);
    pthread_mutex_unlock(fork_l);
    pthread_mutex_unlock(fork_r);
}

void *routine(void *obj)
{
    t_phil *phil = (t_phil *)obj;
    phil->last_meal = get_time();

    while(get_time() - phil->last_meal < phil->time_to_die * 1000)
    {
        do_eat(phil->num, phil->fork_r, phil->fork_l, phil->time_to_eat);
        phil->last_meal = get_time();
        do_sleep(phil->num, phil->time_to_sleep);
        do_think(phil->num, phil->time_to_die, phil->last_meal);
    }
    printf("%d %d is dead\n", get_time() / 1000, phil->num);
    exit(0);
    return (NULL);
}

t_phil *make_phil(t_mutex *forks, int index, char **argv)
{
    t_phil *phil;

    printf("Creating phil number %d\n", index + 1);
    phil                = malloc(sizeof(t_phil));
    phil->num           = index + 1;
    phil->num_of_phil   = atoi(argv[1]);
    phil->time_to_die   = atoi(argv[2]);
    phil->time_to_eat   = atoi(argv[3]);
    phil->time_to_sleep = atoi(argv[4]);
    phil->fork_r        = forks + index;
    if (index == phil->num_of_phil - 1)
        phil->fork_l = forks;
    else
        phil->fork_l = forks + index + 1;
    phil->thread        = malloc(sizeof(t_thread *));
    pthread_create(phil->thread, NULL, routine, phil);
    return phil;
}

