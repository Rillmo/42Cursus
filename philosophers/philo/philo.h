/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:42:12 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/26 18:51:55 by junkim2          ###   ########.fr       */
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

typedef struct timeval t_timeval;

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_eat;
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
	long long	start_time;
	long long	last_eat_time;
}	t_philo;

int			ft_atoi(const char *str);
int			set_info(t_info *info, int argc, char **argv);
int			set_philo(t_philo **philos, t_info *info);
int			philo_thread(t_philo *philos);
long long	get_timenow(void);
void		philo_print(t_philo *philo, t_info *info, int message);

#endif