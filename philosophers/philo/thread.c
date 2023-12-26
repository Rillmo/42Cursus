/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:20:15 by macbookpro        #+#    #+#             */
/*   Updated: 2023/12/26 17:31:37 by junkim2          ###   ########.fr       */
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
void	philo_print(t_philo *philo, t_info *info, int message, long long now)
{
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

void	philo_eat(t_philo *philo, t_info *info)
{
	long long	now;

	now = get_timenow();
	philo->turn_end = 0;
	pthread_mutex_lock(&info->forks[philo->left]);
	philo_print(philo, info, 1, now);
	pthread_mutex_lock(&info->forks[philo->right]);
	philo_print(philo, info, 1, now);
	philo_print(philo, info, 2, now);
	usleep((info->time_to_eat) * 1000);
	philo->turn_end = 1;
	philo_print(philo, info, 3, get_timenow());
	pthread_mutex_unlock(&info->forks[philo->right]);
	pthread_mutex_unlock(&info->forks[philo->left]);
}

void	*philo_func(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	philo->start_time = get_timenow();
	if (philo->num % 2 == 0)
		usleep(25);
	while (1)
	{
		philo_eat(philo, info);
	}
	return (0);
}

int	philo_thread(t_philo *philos)
{
	int		i;
	t_info	*info;

	info = philos[0].info;
	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_create(&philos[i].thread, NULL, philo_func, &philos[i]);
		i++;
	}
	i = 0;
	while (i < info->num_of_philo)
		pthread_join(philos[i++].thread, NULL);
	return (0);
}
