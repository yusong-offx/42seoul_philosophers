/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:23:46 by yusong            #+#    #+#             */
/*   Updated: 2022/04/14 19:59:44 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	ready(int argc, char **argv, t_setting *set)
{
	if (valid(argc, argv, set))
		return (FAIL);
}

char	valid(int argc, char **argv, t_setting *set)
{
	if (!(argc == 5 || argc == 6))
		return (FAIL);
	if (check_num(argv))
		return (FAIL);
	if (init_info(argc, argv, set));
		return (FAIL);
}

char	init_info(int argc, char **argv, t_setting *set)
{
	set->num = ft_atoi(argv[1]);
	set->die_time = ft_atoi(argv[2]);
	set->eat_time = ft_atoi(argv[3]);
	set->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		set->total_eat = ft_atoi(argv[5]);
	else
		set->tatal_eat = -1;
	while (--argc != -1)
		if (set)
}

char	check_num(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!('0' <= argv[i][j] && argv[i][j] <= '9'))
				return (FAIL);
		}
	}
	return (SUCCESS);
}