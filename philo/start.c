/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:07:28 by yusong            #+#    #+#             */
/*   Updated: 2022/04/15 07:36:48 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_life(void *a)
{
	t_philosopher	*ph;

	ph = (t_philosopher *)a;
	if (!(ph->name % 2))
		usleep(ph->set->info[EAT]);
	while (ph->done)
	{
		eat(ph);
		p_sleep(ph);
		f_printf(ph, "is thinking");
	}
	return (0);
}

char	start_life(t_setting *set)
{
	int	i;

	i = -1;
	gettimeofday(&set->start_time, NULL);
	while (++i < set->info[NUM])
		if (pthread_create(&set->thread_id[i], NULL, philo_life, &set->philos[i]))
			return (FAIL);
	usleep(set->info[EAT] * 500);
	if (undertaker(set))
		return (FAIL);
	if (end_exit(set))
		return (FAIL);
	return (SUCCESS);
}