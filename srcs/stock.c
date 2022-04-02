#include "../includes/headerfile.h"

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

void    init_philo(int must_eat)
{
    int i;
    int base;

    i = -1;
    base = g_phoinfo.num;
    while (++i < g_phoinfo.num)
    {
        g_phoinfo.philo[i].name = i + 1;
        g_phoinfo.philo[i].left = &g_phoinfo.fork[i];
        g_phoinfo.philo[i].right = &g_phoinfo.fork[(base + 1 + i) % g_phoinfo.num];
        g_phoinfo.philo[i].left_m = &g_phoinfo.mid[i];
        g_phoinfo.philo[i].right_m = &g_phoinfo.mid[(base + 1 + i) % g_phoinfo.num];
        g_phoinfo.philo[i].must_eat_cnt = must_eat;
    }
}

void    init_phoinfo(int *info)
{
    int cnt;

    g_phoinfo.num = info[0];
    g_phoinfo.die = info[1];
    g_phoinfo.eat = info[2];
    g_phoinfo.sleep = info[3];
    g_phoinfo.fork = safe_malloc(g_phoinfo.num *sizeof(char));
    g_phoinfo.philo = safe_malloc(g_phoinfo.num * sizeof(t_philo));
    g_phoinfo.mid = safe_malloc(g_phoinfo.num * sizeof(pthread_mutex_t));
    cnt = info[0];
    while (cnt)
    {
        cnt--;
        pthread_mutex_init(&g_phoinfo.mid[cnt], NULL);
        g_phoinfo.fork[cnt] = 1;
    }
}

