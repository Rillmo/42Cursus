/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:42:12 by junkim2           #+#    #+#             */
/*   Updated: 2024/01/15 20:23:57 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define _ERROR 1

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_eat;
	int				simulation_end;
	int				eat_end;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printer;
}	t_info;

typedef struct s_philo
{
	t_info		*info;
	pthread_t	thread;
	int			num;
	int			left;
	int			right;
	long long	last_eat;
	int			count;
}	t_philo;

int			ft_atoi(const char *str);
int			set_info(t_info *info, int argc, char **argv);
int			set_philo(t_philo **philos, t_info *info);
int			philo_thread(t_philo *philos);
long long	get_timenow(void);
void		philo_print(t_philo *philo, t_info *info, int message);
int			check_die(t_philo *philo, t_info *info);
int			move_time(t_info *info, int time);
void		destroy_all(t_philo *philos, t_info *info);
void		sleep_until_even_eat(t_info *arg);
void		sleep_while_even_eat(t_info *info);

#endif