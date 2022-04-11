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

void	setting_free(t_setting *set)
{
	free(set->philosophers);
	free(set->mid);
	free(set->pid);
}

char	step_malloc(t_setting *set)
{
	set->philosophers = malloc(sizeof(t_philosopher) * set->num);
	if (!set->philosophers)
		return (1);
	set->mid = malloc(sizeof(pthread_mutex_t) * set->num);
	if (!set->mid)
	{
		free(set->philosophers);
		return (1);
	}
	set->pid = malloc(sizeof(pthread_t) * set->num);
	if (!set->pid)
	{
		free(set->philosophers);
		free(set->mid);
		return (1);
	}
	return (0);
}