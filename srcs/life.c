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
int	g_eat;
pthread_mutex_t tmp;
void test()
{
	pthread_mutex_lock(&tmp);
	g_eat++;
	pthread_mutex_unlock(&tmp);
}

void	eat(t_philosopher *ph)
{
	if ((ph->name) % 2)
	{
		pthread_mutex_lock(ph->left);
		f_printf(ph, "has taken a fork.");
		pthread_mutex_lock(ph->right);
		f_printf(ph, "has taken a fork.");
	}
	else
	{
		pthread_mutex_lock(ph->right);
		f_printf(ph, "has taken a fork.");
		pthread_mutex_lock(ph->left);
		f_printf(ph, "has taken a fork.");
	}
	f_printf(ph, "is eating.");
	my_sleep(ph->set->eat_time);
	pthread_mutex_unlock(ph->left);
	pthread_mutex_unlock(ph->right);
}

void	life_sleep(t_philosopher *ph)
{
	f_printf(ph, "is sleeping.");
	my_sleep(ph->set->sleep_time);
}

void	*life(void *a)
{
	t_philosopher	*ph;

	ph = (t_philosopher *)a;
	ph->prev_eat_time = get_time() - ph->set->start_time;
	while (ph->eat_cnt && ph->set->end_flag == -1)
	{
		eat(ph);
		usleep(1500);
		ph->eat_cnt--;
		ph->prev_eat_time = get_time() - ph->set->start_time;
		life_sleep(ph);
		f_printf(ph, "is thinking.");
	}
	test();
	return (0);
}



char	life_start(t_setting *set)
{
	int	i;
	int	start;

	pthread_mutex_init(&tmp, NULL);
	i = -1;
	set->start_time = get_time();
	while (++i < set->num)
		if (pthread_create(&(set->pid[i]), NULL, life, &(set->philosophers[i])))
			return (0);
	while(1)
	{
		if (g_eat == set->num)
			break;
		else if (set->end_flag != -1)
			return (0);
	}
	i = -1;
	while (++i < set->num)
		pthread_join(set->pid[i], NULL);
	if (set->end_flag != -1)
		return (0);
	return (1);
}
