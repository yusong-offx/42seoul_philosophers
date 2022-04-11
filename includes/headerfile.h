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
	struct s_setting	*set;
	pthread_mutex_t		*left;
	pthread_mutex_t		*right;
	suseconds_t			prev_eat_time;
	suseconds_t			start_time;
	int					name;
	int					eat_cnt;
}						t_philosopher;

typedef struct s_setting
{
	pthread_mutex_t	m_end_life;
	pthread_mutex_t	m_print;
	pthread_mutex_t	*mid;
	t_philosopher	*philosophers;
	suseconds_t		start_time;
	pthread_t		*pid;
	int				i;
	int				num;
	int				die_time;
	int				sleep_time;
	int				eat_time;
	int				eat_cnt;
	int				end_flag;
	int				end_life_cnt;
}					t_setting;

// main.c
char		death_checker(t_setting *set);

// life.c
void 		end_life_counter(t_philosopher *ph);
void		eat(t_philosopher *ph);
void		life_sleep(t_philosopher *ph);
void		*life(void *a);
char		life_start(t_setting *set);

// init.c
char		valid_argv(int argc, char **argv, int *info);
void		init_info(char **argv, int *info);
char		init_philosophers(t_setting *set);
char		init(int *info, t_setting *set);

// utils
int			ft_atoi(const char *str);
char		is_num(char *c);
suseconds_t	get_time(void);
void		my_sleep(int time);
void		f_printf(t_philosopher *ph, char *s);

// free.c
void		setting_free(t_setting *set);
char		step_malloc(t_setting *set);

#endif