/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:37:37 by yusong            #+#    #+#             */
/*   Updated: 2022/04/15 08:39:21 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	end_exit(t_setting *set)
{
	int	i;

	i = -1;
	while (++i < set->info[NUM])
		if (pthread_join(set->thread_id[i], NULL))
			return (FAIL);
	i = -1;
	while (++i < set->info[NUM])
		if (pthread_mutex_destroy(&set->fork_mutex[i]))
			return (FAIL);
	if (pthread_mutex_destroy(&set->print_mutex))
		return (FAIL);
	free(set->fork_mutex);
	free(set->thread_id);
	free(set->philos);
	return (SUCCESS);
}

char	undertaker(t_setting *set)
{
	int	i;
	int	j;

	while (set->done)
	{
		usleep(10);
		i = -1;
		while (++i < set->info[NUM] && set->done)
			if (set->philos[i].done && get_now(set->start_time) >= \
				set->philos[i].prev_eat_time + set->info[DIE])
			{
				pthread_mutex_lock(&set->print_mutex);
				printf("%ld %d %s\n", get_now(set->start_time), set->philos[i].name, "die");
				return (FAIL);
			}
	}
	return (SUCCESS);
}

void	var_done(t_philosopher *ph)
{
	pthread_mutex_lock(&ph->set->print_mutex);
	ph->set->done--;
	pthread_mutex_unlock(&ph->set->print_mutex);
}