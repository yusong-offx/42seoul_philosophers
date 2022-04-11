/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:45:59 by yusong            #+#    #+#             */
/*   Updated: 2022/04/04 15:13:37 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headerfile.h"

char	valid_argv(int argc, char **argv, int *info)
{
	int	i;

	if (argc == 5 || argc == 6)
	{
		i = 1;
		while (argv[i])
		{
			if (!is_num(argv[i]))
				return (0);
			i++;
		}
		init_info(argv, info);
		if (info[1] <= 0)
			return (0);
		return (1);
	}
	return (0);
}

void	init_info(char **argv, int *info)
{
	int	i;

	info[5] = -1;
	i = 1;
	while (argv[i])
	{
		info[i] = ft_atoi(argv[i]);
		i++;
	}
}

char	init_philosophers(t_setting *set)
{
	int	i;

	if (step_malloc(set))
		return (0);
	i = -1;
	while (++i < set->num)
		if (pthread_mutex_init(&(set->mid[i]), NULL))
		{
			setting_free(set);
			return (0);
		}
	i = -1;
	while (++i < set->num)
	{
		set->philosophers[i].left = &(set->mid[i]);
		set->philosophers[i].right = &(set->mid[(i + 1) % set->num]);
		set->philosophers[i].name = i + 1;
		set->philosophers[i].eat_cnt = set->eat_cnt;
		set->philosophers[i].set = set;
		set->philosophers[i].prev_eat_time = 0;
	}
	return (1);
}

char	init(int *info, t_setting *set)
{
	set->num = info[1];
	if (set->num == 1)
		set->num++;
	set->end_life_cnt = info[1];
	set->die_time = info[2];
	set->eat_time = info[3];
	set->sleep_time = info[4];
	set->eat_cnt = info[5];
	set->end_flag = -1;
	if (init_philosophers(set) && !pthread_mutex_init(&(set->m_print), NULL))
	{
		if (info[1] == 1)
			set->num--;
		return (1);
	}
	return (0);
}
