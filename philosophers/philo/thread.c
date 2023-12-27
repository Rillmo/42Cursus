/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:20:15 by macbookpro        #+#    #+#             */
/*   Updated: 2023/12/27 14:56:49 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo, t_info *info)
{
	philo_print(philo, info, 4);
	pthread_mutex_lock(&info->forks[philo->left]);
	philo_print(philo, info, 1);
	pthread_mutex_lock(&info->forks[philo->right]);
	philo_print(philo, info, 1);
	philo_print(philo, info, 2);
	philo->last_eat = get_timenow();
	while (get_timenow() - philo->last_eat < info->time_to_eat)
	{
		usleep(100);
		if (get_timenow() - philo->last_eat > info->time_to_die)
		{
			philo_print(philo, info, 5);
			exit(1);
		}
	}

	pthread_mutex_unlock(&info->forks[philo->right]);
	pthread_mutex_unlock(&info->forks[philo->left]);
}

void	*philo_func(void *arg)
{
	t_philo	*philo;
	t_info	*info;
	long long	start;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->num % 2 == 0)
	{
		philo_print(philo, info, 3);
		usleep(100);
	}
	while (1)
	{
		philo_eat(philo, info);
		philo_print(philo, info, 3);
		start = get_timenow();
		while (get_timenow() - start < info->time_to_sleep)
		{
			usleep(100);
			if (get_timenow() - philo->last_eat > info->time_to_die)
			{
				philo_print(philo, info, 5);
				exit(1);
			}
		}
	}
	return (0);
}

void	monitoring(t_philo *philos, t_info *info)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < info->num_of_philo)
		{
			if (get_timenow() - philos[i].last_eat > info->time_to_die)
			{
				philo_print(&philos[i], info , 5);
				exit(1);
			}
			i++;
		}
	}
}

int	philo_thread(t_philo *philos)
{
	int		i;
	t_info	*info;

	info = philos[0].info;
	i = 0;
	while (i < info->num_of_philo)
	{
		philos[i].start_time = get_timenow();
		philos[i].last_eat = philos[i].start_time;
		pthread_create(&philos[i].thread, NULL, philo_func, &philos[i]);
		i++;
	}
	monitoring(philos, info);
	i = 0;
	while (i < info->num_of_philo)
		pthread_join(philos[i++].thread, NULL);
	return (0);
}
