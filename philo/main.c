/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:17:22 by yusong            #+#    #+#             */
/*   Updated: 2022/04/15 07:38:58 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_setting	set;
	pthread_mutex_init(&tmp, NULL);
	if (ready(argc, argv, &set))
	{
		printf("init something wrong\n");
		return (FAIL);
	}
	if (start_life(&set))
	{
		printf("life something wrong\n");
		return (FAIL);
	}
	return (SUCCESS);
}
