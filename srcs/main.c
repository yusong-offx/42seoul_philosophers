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
void	checker(t_setting *set)
{
	printf("num %d\n", set->num);
	printf("die %d\n",set->die_time);
	printf("sleep %d\n",set->sleep_time);
	printf("eat %d\n",set->eat_time);
	printf("eat_cnt %d\n",set->eat_cnt);
	printf("\n");
	printf("philo\n");
	for (int i = 0; i < set->num; i++)
	{
		printf("name %d\n",set->philosophers[i].name);
		printf("left %p\n",set->philosophers[i].left);
		printf("right %p\n",set->philosophers[i].right);
		printf("eat_cnt %d\n",set->philosophers[i].eat_cnt);
		printf("\n");
	}
}

int	main(int argc, char **argv)
{
	int			info[6];
	t_setting	set;

	if (!valid_argv(argc, argv, info))
	{
		printf("input error\n");
		return (1);
	}
	if (!init(info, &set))
	{
		printf("malloc error\n");
		return (1);
	}
	checker(&set);
	if (!life_start(&set))
	{
		printf("life something wrong");
		return (1);
	}
	printf("=== main end ===\n");
	return (0);
}
