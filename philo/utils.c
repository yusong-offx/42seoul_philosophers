/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:43:53 by yusong            #+#    #+#             */
/*   Updated: 2022/04/15 07:38:46 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		if (num > 21474483647 || num < -2147483648)
			return (-1);
		str++;
	}
	return (num);
}

suseconds_t	get_now(struct timeval st)
{
	struct timeval	now;
	// suseconds_t		tmp1;
	// suseconds_t		tmp2;
	// tmp1 = now.tv_sec * 1000 + now.tv_usec / 1000;
	// tmp2 = st.tv_sec * 1000 + st.tv_usec / 1000;
	// return (tmp1 - tmp2);

	gettimeofday(&now, NULL);
	return ((now.tv_sec - st.tv_sec) * 1000 + (now.tv_usec - st.tv_usec) / 1000);
}

void	mysleep(int itv)
{
	struct timeval	now;
	suseconds_t		base;

	gettimeofday(&now, NULL);
	base = now.tv_sec * 1000 + now.tv_usec / 1000;
	while (base + itv > (now.tv_sec * 1000 + now.tv_usec / 1000))
	{
		usleep(300);
		gettimeofday(&now, NULL);
	}
}

void	f_printf(t_philosopher *ph, char *s)
{
	pthread_mutex_lock(ph->my_mutex);
	pthread_mutex_lock(&tmp);
	printf("%ld %d %s\n", get_now(ph->set->start_time), ph->name, s);
	pthread_mutex_unlock(&tmp);
	pthread_mutex_unlock(ph->my_mutex);
}