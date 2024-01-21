/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:36:52 by junkim2           #+#    #+#             */
/*   Updated: 2024/01/17 17:43:13 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_eatend(t_info *info, int n)
{
	pthread_mutex_lock(&info->eatend);
	info->eat_end = info->eat_end + n;
	pthread_mutex_unlock(&info->eatend);
}

void	set_lasteat(t_philo *philo, t_info *info, long long time)
{
	pthread_mutex_lock(&(info->lasteat[philo->num]));
	philo->last_eat = time;
	pthread_mutex_unlock(&(info->lasteat[philo->num]));
}

void	set_end(t_info *info, int flag)
{
	pthread_mutex_lock(&info->end);
	info->simulation_end = flag;
	pthread_mutex_unlock(&info->end);
}
