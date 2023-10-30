#include "philosophers.h"

int main(int argc, char **argv)
{
    if (argc < 5)
        return (1);

    int         num_of_phil = atoi(argv[1]);
    t_phil      *phils[num_of_phil];
    t_mutex     forks[num_of_phil];

    printf("%d\n", get_time());
    for (int i = 0; i < num_of_phil; i++)
        pthread_mutex_init(forks + i, NULL);
    for (int i = 0; i < num_of_phil; i++)
        phils[i] = make_phil(forks, i, argv);
    for (int i = 0; i < num_of_phil; i++)
        pthread_join(*(phils[i]->thread), NULL);
    return (0);
}
