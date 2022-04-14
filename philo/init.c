/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:23:46 by yusong            #+#    #+#             */
/*   Updated: 2022/04/15 06:58:38 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	ready(int argc, char **argv, t_setting *set)
{
	if (valid(argc, argv))
		return (FAIL);
	if (init_info(argc, argv, set))
		return (FAIL);
	if (init_philo(set))
		return (FAIL);
	return (SUCCESS);
}

char	valid(int argc, char **argv)
{
	if (!(argc == 5 || argc == 6))
		return (FAIL);
	if (check_num(argv))
		return (FAIL);
	return (SUCCESS);
}

char	init_philo(t_setting *set)
{
	int	i;

	set->thread_id = (pthread_t *)malloc(set->info[NUM] * sizeof(pthread_t));
	set->philos = (t_philosopher *)malloc(set->info[NUM] * sizeof(t_philosopher));
	if (!(set->thread_id && set->philos))
		return (FAIL);
	i = -1;
	while (++i < set->info[NUM])
		if (pthread_mutex_init(&set->fork_mutex[i], NULL) || pthread_mutex_init(&set->philo_mutex[i], NULL))
			return (FAIL);
	i = -1;
	while (++i < set->info[NUM])
	{
		set->philos[i].name = i + 1;
		set->philos[i].my_mutex = &set->philo_mutex[i];
		set->philos[i].fork_left = &set->fork_mutex[i];
		set->philos[i].fork_right = &set->fork_mutex[(i + 1) % set->info[NUM]];
		set->philos[i].prev_eat_time = 0;
		set->philos[i].done = set->info[DONE];
		set->philos[i].set = set;
	}
	return (SUCCESS);
}


char	init_info(int argc, char **argv, t_setting *set)
{
	int	i;

	i = 0;
	set->info[5] = -1;
	while (++i < argc)
	{
		set->info[i] = ft_atoi(argv[i]);
		if (set->info[i] < 0)
			return (FAIL);
	}
	if (set->info[1] == 0)
		return (FAIL);
	set->fork_mutex = (pthread_mutex_t *)malloc(set->info[NUM] * sizeof(pthread_mutex_t));
	set->philo_mutex = (pthread_mutex_t *)malloc(set->info[NUM] * sizeof(pthread_mutex_t));
	if (!(set->fork_mutex && set->philo_mutex))
		return (FAIL);
	return (SUCCESS);
}

char	check_num(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if (!('0' <= argv[i][j] && argv[i][j] <= '9'))
				return (FAIL);
	}
	return (SUCCESS);
}
