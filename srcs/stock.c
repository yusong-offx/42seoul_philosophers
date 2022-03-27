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

// void    init_philo(t_philo *p, int *info)
// {
//     int i;

//     i = -1;
//     while (i++ < num)
//     {
//         p[i].left_fork = ;
//         p[i].right_fork = ;
//         p[i].eat = info[];
//         p[i].sleep = ;
//         p[i].die = ;
//         p[i].must_eat = ;
//     }
// }