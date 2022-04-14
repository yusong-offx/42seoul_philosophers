/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:16:47 by yusong            #+#    #+#             */
/*   Updated: 2022/04/14 19:54:39 by yusong           ###   ########.fr       */
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

typedef struct s_philosopher
{
	int				name;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	suseconds_t		prev_eat_time;
	int				eat_cnt;
	t_setting		*set;
}	t_philosopher;

typedef struct s_setting
{
	int				num;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*philo_mutex;
	pthread_t		*tid;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				total_eat;
	suseconds_t		start_time;
	t_philosopher	*philos;
}	t_setting;

// utils.c
int	ft_atoi(const char *str);

#endif