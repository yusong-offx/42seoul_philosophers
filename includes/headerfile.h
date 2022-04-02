#ifndef HEADERFILE_H
# define HEADERFILE_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct      s_philo
{
    int             name;
    char            *left;
    char            *right;
    pthread_mutex_t *left_m;
    pthread_mutex_t *right_m;
    int             must_eat_cnt;
}                   t_philo;

typedef struct      s_phoinfo
{
    t_philo         *philo;
    char            *fork;
    pthread_mutex_t *mid;
    int             num;
    int             eat;
    int             sleep;
    int             die;
}                   t_phoinfo;
t_phoinfo           g_phoinfo;
suseconds_t         g_start;

// SRCS
void    error_exit(char *msg);
void    init_info(int *info, char **argv);
void    init_phoinfo(int *info);
void    init_philo(int must_eat);
void    live(void);
// UTILS
int	    ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void    *safe_malloc(int size);

#endif