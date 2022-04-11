/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:43:18 by yusong            #+#    #+#             */
/*   Updated: 2022/04/04 15:14:04 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headerfile.h"

int	main(int argc, char **argv)
{
	int			info[6];
	t_setting	set;

	if (!valid_argv(argc, argv, info))
	{
		printf("input error.\n");
		return (1);
	}
	if (!init(info, &set))
	{
		printf("init error.\n");
		return (1);
	}
	if (!life_start(&set))
	{
		printf("life something wrong.\n");
		return (1);
	}
	printf("all live... Life is continue...\n");
	return (0);
}

char	death_checker(t_setting *set)
{
	int	i;

	while (set->end_life_cnt)
	{
		i = -1;
		while (++i < set->num)
		{
			if (set->philosophers[i].prev_eat_time + set->die_time <= get_time() - set->philosophers[i].start_time)
			{
				set->end_flag = set->philosophers[i].name;
				printf("[%10ldms] %d %s\n", get_time() - set->start_time, set->philosophers[i].name, "died.");
				i = -1;
				while (++i < set->num)
				{
					pthread_detach(set->pid[i]);
					pthread_mutex_destroy(&set->mid[i]);
				}
				setting_free(set);
				return (1);
			}
		}
	}
	return (0);
}
