/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:09:27 by yusong            #+#    #+#             */
/*   Updated: 2022/04/04 15:11:24 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headerfile.h"

int	ft_atoi(const char *str)
{
	long int	num;
	int			n;

	n = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = n * -1;
	str++;
	}
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0') * n;
		if (num > 21474483647)
			return (-1);
		if (num < -2147483648)
			return (0);
		str++;
	}
	return (num);
}

char	is_num(char *c)
{
	int	i;

	if (!*c)
		return (0);
	i = 0;
	while (c[i])
	{
		if (!('0' <= c[i] && c[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

suseconds_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec);
}

void	my_sleep(int time)
{
	suseconds_t	now;

	now = get_time() + time * 1000;
	while (now > get_time())
		usleep(1000);
}

void	f_printf(int i, char *s)
{
	pthread_mutex_lock(&g_mtx);
	printf("[%10dms] %d %s\n",(get_time() - g_time) / 1000, i, s);
	pthread_mutex_unlock(&g_mtx);
}
