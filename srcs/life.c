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

void	eat(t_philosopher *ph)
{
	if ((ph->name) % 2)
	{
		pthread_mutex_lock(ph->left);
		f_printf(ph->name, "has taken a fork.", ph->set->start_time);
		pthread_mutex_lock(ph->right);
		f_printf(ph->name, "has taken a fork.", ph->set->start_time);
		f_printf(ph->name, "is eating.", ph->set->start_time);
		my_sleep(ph->set->eat_time);
		pthread_mutex_unlock(ph->left);
		pthread_mutex_unlock(ph->right);
	}
	else
	{
		pthread_mutex_lock(ph->right);
		f_printf(ph->name, "has taken a fork.", ph->set->start_time);
		pthread_mutex_lock(ph->left);
		f_printf(ph->name, "has taken a fork.", ph->set->start_time);
		f_printf(ph->name, "is eating.", ph->set->start_time);
		my_sleep(ph->set->eat_time);
		pthread_mutex_unlock(ph->left);
		pthread_mutex_unlock(ph->right);
	}
}

void	life_sleep(t_philosopher *ph)
{
	f_printf(ph->name, "is sleeping.", ph->set->start_time);
	my_sleep(ph->set->sleep_time);
}

void	*life(void *a)
{
	t_philosopher	*ph;

	ph = (t_philosopher *)a;
	ph->prev_eat_time = get_time();
	while (ph->eat_cnt)
	{
		if ((get_time() - ph->prev_eat_time) > ph->set->die_time)
		{
			printf("%d die\n", ph->name);
			exit(0);
		}
		f_printf(ph->name, "is thinking.", ph->set->start_time);
		eat(ph);
		ph->eat_cnt--;
		ph->prev_eat_time = get_time();
		life_sleep(ph);
	}
	return (0);
}

char	life_start(t_setting *set)
{
	int			i;

	i = 0;
	set->start_time = get_time();
	while (i < set->num)
	{
		if (pthread_create(&(set->pid[i]), NULL, life, &(set->philosophers[i])))
			return (0);
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
