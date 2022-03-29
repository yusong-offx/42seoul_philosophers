#ifndef HEADERFILE_H
# define HEADERFILE_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct  s_philo
{
    char        left_fork;
    char        right_fork;
    int         must_eat_cnt;
}               t_philo;

typedef struct      s_phoinfo
{
    pthread_t       *tid;
    pthread_mutex_t *mid;
    int             num;
    int             eat;
    int             sleep;
    int             die;
}                   t_phoinfo;

// SRCS
void    init_info(int *info, char **argv);
void    error_exit(char *msg);
void    init_phoinfo(t_phoinfo *phoinfo, int *info);

// UTILS
int	    ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void    *safe_malloc(int size);

#endif