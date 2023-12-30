/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 23:31:58 by macbookpro        #+#    #+#             */
/*   Updated: 2023/12/30 14:42:48 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_all(t_philo *philos, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	free(philos);
	free(info->forks);
}

long long	get_timenow(void)
{
	struct timeval	now;
	long long		result;

	if (gettimeofday(&now, NULL) == -1)
		return (_ERROR);
	result = now.tv_sec * 1000 + now.tv_usec / 1000;
	return (result);
}

int	check_die(t_philo *philo, t_info *info)
{
	long long	now;

	now = get_timenow();
	if (now == _ERROR)
		return (_ERROR);
	if (get_timenow() - philo->last_eat >= info->time_to_die)
	{
		info->simulation_end = 1;
		philo_print(philo, info, 5);
		return (1);
	}
	return (0);
}

int	move_time(t_info *info, int time)
{
	long long	start;
	long long	now;

	start = get_timenow();
	if (start == _ERROR)
		return (_ERROR);
	now = start;
	while (now - start < time)
	{
		now = get_timenow();
		if (now == _ERROR)
			return (_ERROR);
		if (info->simulation_end == 1)
			return (0);
		usleep(100);
	}
	return (0);
}

// <message>	1)fork  2)eat  3)sleep  4)think  5)die
void	philo_print(t_philo *philo, t_info *info, int message)
{
	long long	now;

	pthread_mutex_lock(&info->printer);
	now = get_timenow();
	if (message == 5)
		printf("%lld %d died\n", now - info->start_time, philo->num + 1);
	if (info->simulation_end == 1)
	{
		pthread_mutex_unlock(&info->printer);
		return ;
	}
	if (message == 1)
		printf("%lld %d has taken a fork\n", \
		now - info->start_time, philo->num + 1);
	if (message == 2)
		printf("%lld %d is eating\n", now - info->start_time, philo->num + 1);
	if (message == 3)
		printf("%lld %d is sleeping\n", now - info->start_time, philo->num + 1);
	if (message == 4)
		printf("%lld %d is thinking\n", now - info->start_time, philo->num + 1);
	pthread_mutex_unlock(&info->printer);
}
