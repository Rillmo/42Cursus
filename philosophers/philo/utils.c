/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 23:31:58 by macbookpro        #+#    #+#             */
/*   Updated: 2023/12/26 22:43:13 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_timenow(void)
{
	t_timeval	now;
	long long	result;

	if (gettimeofday(&now, NULL) < 0)
		return (-1);
	result = now.tv_sec * 1000 + now.tv_usec / 1000;
	return (result);
}

// <message>	1)fork  2)eat  3)sleep  4)think  5)die
void	philo_print(t_philo *philo, t_info *info, int message)
{
	long long	now;

	now = get_timenow();
	pthread_mutex_lock(&info->printer);
	if (message == 1)
		printf("%lld %d has taken a fork\n", \
		now - philo->start_time, philo->num);
	else if (message == 2)
		printf("%lld %d is eating\n", now - philo->start_time, philo->num);
	else if (message == 3)
		printf("%lld %d is sleeping\n", now - philo->start_time, philo->num);
	else if (message == 4)
		printf("%lld %d is thinking\n", now - philo->start_time, philo->num);
	else
		printf("%lld %d died\n", now - philo->start_time, philo->num);
	pthread_mutex_unlock(&info->printer);
}
