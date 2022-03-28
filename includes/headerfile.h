#ifndef HEADERFILE_H
# define HEADERFILE_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>



typedef struct  s_philo
{
    char left_fork;
    char right_fork;
    int eat;
    int sleep;
    int die;
    int must_eat;
}                t_philo;

// typedef struct  s_pginfo
// {
//     pthread_t   *tid;
//     m
// }

// SRCS
void    init_info(int *info, char **argv);
void    error_exit(char *msg);


// UTILS
int	    ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void    *safe_malloc(int size);

#endif