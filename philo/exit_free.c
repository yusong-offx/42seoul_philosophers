/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:37:37 by yusong            #+#    #+#             */
/*   Updated: 2022/04/15 07:27:20 by yusong           ###   ########.fr       */
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
	set->info[DONE] = 0;
	i = -1;
	while (++i < set->info[NUM])
		if (pthread_mutex_destroy(&set->fork_mutex[i])|| \
			pthread_mutex_destroy(&set->philo_mutex[i]))
			return (FAIL);
	free(set->fork_mutex);
	free(set->philo_mutex);
	free(set->thread_id);
	free(set->philos);
	return (SUCCESS);
}

char	undertaker(t_setting *set)
{
	int	i;
	int	j;

	while (set->info[DONE])
	{
		usleep(10);
		i = -1;
		while (++i < set->info[NUM] && set->info[DONE])
			if (get_now(set->start_time) >= \
				set->philos[i].prev_eat_time + set->info[DIE])
			{
				j = -1;
				while (++j < set->info[NUM])
					pthread_mutex_lock(set->philos[j].my_mutex);
				printf("%ld %d %s\n", get_now(set->start_time), set->philos[i].name, "die");
				return (FAIL);
			}
	}
	return (SUCCESS);
}
