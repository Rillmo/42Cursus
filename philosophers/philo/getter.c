/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:39:51 by junkim2           #+#    #+#             */
/*   Updated: 2024/01/17 17:43:17 by junkim2          ###   ########.fr       */
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

int	get_eatend(t_info *info)
{
	int	result;

	pthread_mutex_lock(&info->eatend);
	result = info->eat_end;
	pthread_mutex_unlock(&info->eatend);
	return (result);
}

int	get_end(t_info *info)
{
	int	result;

	pthread_mutex_lock(&info->end);
	result = info->simulation_end;
	pthread_mutex_unlock(&info->end);
	return (result);
}
