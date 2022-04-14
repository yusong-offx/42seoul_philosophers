/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:16:47 by yusong            #+#    #+#             */
/*   Updated: 2022/04/15 08:36:52 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define SUCCESS	0
# define FAIL		1

typedef enum e_info {
	NUM = 1,
	DIE,
	EAT,
	SLEEP,
	DONE,
}	t_info;

typedef struct s_philosopher
{
	int					name;
	pthread_mutex_t		*fork_left;
	pthread_mutex_t		*fork_right;
	suseconds_t			prev_eat_time;
	int					done;
	struct s_setting	*set;
}	t_philosopher;

typedef struct s_setting
{
	int				info[6];
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*philo_mutex;
	pthread_mutex_t	print_mutex;
	pthread_t		*thread_id;
	struct timeval	start_time;
	int				done;
	t_philosopher	*philos;
}	t_setting;

// exit_free.c
char		end_exit(t_setting *set);
char		undertaker(t_setting *set);
void		var_done(t_philosopher *ph);

// init.c
char		ready(int argc, char **argv, t_setting *set);
char		valid(int argc, char **argv);
char		init_philo(t_setting *set);
char		init_info(int argc, char **argv, t_setting *set);
char		check_num(char **argv);

// start.c
void		*philo_life(void *a);
char		start_life(t_setting *set);

// utils.c
int			ft_atoi(const char *str);
suseconds_t	get_now(struct timeval st);
void		mysleep(int itv);
void		f_printf(t_philosopher *ph, char *s);

// life.c
void		eat(t_philosopher *ph);
void		p_sleep(t_philosopher *ph);

#endif