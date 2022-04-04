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
		printf("input error\n");
		return (1);
	}
	if (!init(info, &set))
	{
		printf("malloc error\n");
		return (1);
	}
	// checker(&set);
	if (!life_start(&set))
	{
		printf("life something wrong");
		return (1);
	}
	printf("=== main end ===\n");
	return (0);
}
