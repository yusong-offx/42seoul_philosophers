/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:19:14 by yusong            #+#    #+#             */
/*   Updated: 2022/04/04 15:11:31 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headerfile.h"

void	take_fork(t_setting *set)
{
	t_philosopher	ph;

	ph = set->philosophers[set->i];
	if ((set->i) % 2)
	{
		pthread_mutex_lock(ph.left);
		f_printf(ph.name, "has taken a  fork.");
		pthread_mutex_lock(ph.right);
		f_printf(ph.name, "has taken a  fork.");
	}
	else
	{
		pthread_mutex_lock(ph.right);
		f_printf(ph.name, "has taken a  fork.");
		pthread_mutex_lock(ph.left);
		f_printf(ph.name, "has taken a  fork.");
	}
}

void	eat(t_setting *set)
{
	t_philosopher	ph;

	ph = set->philosophers[set->i];
	f_printf(ph.name, "is eating.");
	my_sleep(set->eat_time);
	pthread_mutex_unlock(ph.left);
	pthread_mutex_unlock(ph.right);
}

void	life_sleep(t_setting *set)
{
	t_philosopher	ph;

	ph = set->philosophers[set->i];
	f_printf(ph.name, "is sleeping.");
	my_sleep(set->sleep_time);
}

void	*life(void *a)
{
	t_setting		*set;
	t_philosopher	ph;

	set = (t_setting *)a;
	ph = set->philosophers[set->i];
	ph.prev_eat_time = get_time();
	while (ph.eat_cnt)
	{
		if ((get_time() - ph.prev_eat_time) / 1000 > set->die_time)
			exit(0);
		f_printf(ph.name, "is thinking.");
		take_fork(set);
		eat(set);
		ph.eat_cnt--;
		life_sleep(set);
	}
	return (0);
}

char	life_start(t_setting *set)
{
	int	i;

	i = 0;
	g_time = get_time();
	pthread_mutex_init(&g_mtx, NULL);
	while (i < set->num)
	{
		set->i = i;
		if (pthread_create(&(set->pid[i]), NULL, life, set))
			return (0);
		usleep(10);
		i++;
	}
	i = 0;
	while (i < set->num)
	{
		pthread_join(set->pid[i], NULL);
		i++;
	}
	return (1);
}
