#include "../includes/headerfile.h"

void    ready(int argc, int *info)
{

}

void    init_info(int *info, char **argv)
{
    int i;

    i = 0;
    while (argv[i+1])
    {
        info[i] = ft_atoi(argv[i+1]);
        i++;
    }
}

void    init_philo(t_philo *philo)
{

}

void    init_phoinfo(t_phoinfo *phoinfo, int *info)
{
    phoinfo->num = info[0];
    phoinfo->die = info[1];
    phoinfo->eat = info[2];
    phoinfo->sleep = info[3];
    phoinfo->tid = (pthread_t)safe_malloc(phoinfo->num * sizeof(pthread_t));
    phoinfo->mid = (pthread_mutex_t)safe_malloc(phoinfo->num * sizeof(pthread_mutex_t));

}

