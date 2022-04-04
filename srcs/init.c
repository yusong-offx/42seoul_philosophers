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

void	init_mid(pthread_mutex_t *mid)
{
	pthread_mutex_init(mid, NULL);
	printf("%p\n", mid);
}

void	init_p(t_philosopher *p, t_setting *set)
{

}

char	init_philosophers(t_setting *set)
{
	int	i;

	set->philosophers = malloc(sizeof(t_philosopher) * set->num);
	set->mid = malloc(sizeof(pthread_mutex_t) * set->num);
	set->pid = malloc(sizeof(pthread_t) * set->num);
	if (!(set->philosophers && set->mid && set->pid))
		return (0);
	i = -1;
	while (++i < set->num)
		pthread_mutex_init(&(set->mid[i]), NULL);
	i = -1;
	while (++i < set->num)
	{
		set->philosophers[i].right = &(set->mid[(set->num - 1 + i) % set->num]);
		set->philosophers[i].left = &(set->mid[(set->num + 1 + i) % set->num]);
		set->philosophers[i].name = i + 1;
		set->philosophers[i].eat_cnt = set->eat_cnt;
	}
	return (1);
}

char	init(int *info, t_setting *set)
{
	set->num = info[1];
	set->die_time = info[2];
	set->eat_time = info[3];
	set->sleep_time = info[4];
	set->eat_cnt = info[5];

	if (init_philosophers(set))
		return (1);
	return (0);
}
