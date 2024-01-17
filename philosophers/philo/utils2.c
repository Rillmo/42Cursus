/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:39:51 by junkim2           #+#    #+#             */
/*   Updated: 2024/01/17 16:50:49 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_lasteat(t_philo *philo, t_info *info)
{
	long long	result;

	pthread_mutex_lock(&(info->lasteat[philo->num]));
	result = philo->last_eat;
	pthread_mutex_unlock(&(info->lasteat[philo->num]));
	return (result);
}

void	set_lasteat(t_philo *philo, t_info *info, long long time)
{
	pthread_mutex_lock(&(info->lasteat[philo->num]));
	philo->last_eat = time;
	pthread_mutex_unlock(&(info->lasteat[philo->num]));
}

int	get_end(t_info *info)
{
	int	result;

	pthread_mutex_lock(&info->end);
	result = info->simulation_end;
	pthread_mutex_unlock(&info->end);
	return (result);
}

void	set_end(t_info *info, int flag)
{
	pthread_mutex_lock(&info->end);
	info->simulation_end = flag;
	pthread_mutex_unlock(&info->end);
}
