/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 06:02:23 by yusong            #+#    #+#             */
/*   Updated: 2022/04/15 07:36:17 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	odd(t_philosopher *ph)
{
	pthread_mutex_lock(ph->fork_left);
	f_printf(ph, "has taken a fork");
	pthread_mutex_lock(ph->fork_right);
	f_printf(ph, "has taken a fork");
}

static void	even(t_philosopher *ph)
{
	pthread_mutex_lock(ph->fork_right);
	f_printf(ph, "has taken a fork");
	pthread_mutex_lock(ph->fork_left);
	f_printf(ph, "has taken a fork");
}

void	eat(t_philosopher *ph)
{
	if (ph->name % 2)
		odd(ph);
	else
		even(ph);
	f_printf(ph, "is eating");
	ph->prev_eat_time = get_now(ph->set->start_time);
	mysleep(ph->set->info[EAT]);
	ph->done--;
	pthread_mutex_unlock(ph->fork_right);
	pthread_mutex_unlock(ph->fork_left);
}

void	p_sleep(t_philosopher *ph)
{
	f_printf(ph, "is sleeping");
	mysleep(ph->set->info[SLEEP]);
}

