/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerfile.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:46:28 by yusong            #+#    #+#             */
/*   Updated: 2022/04/04 15:10:02 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERFILE_H
# define HEADERFILE_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philosopher
{
	int				name;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	int				eat_cnt;
	suseconds_t		prev_eat_time;
}					t_philosopher;

typedef struct s_setting
{
	t_philosopher	*philosophers;
	int				i;
	pthread_t		*pid;
	pthread_mutex_t	*mid;
	int				num;
	int				die_time;
	int				sleep_time;
	int				eat_time;
	int				eat_cnt;
}					t_setting;

suseconds_t g_time;
pthread_mutex_t g_mtx;
// utils
int			ft_atoi(const char *str);
char		is_num(char *c);
suseconds_t	get_time(void);
void		my_sleep(int time);
void		f_printf(int i, char *s);

// init.c
char		valid_argv(int argc, char **argv, int *info);
void		init_info(char **argv, int *info);
char		init_philosophers(t_setting *set);
char		init(int *info, t_setting *set);

// life.c
char		life_start(t_setting *set);

#endif