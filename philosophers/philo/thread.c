/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:20:15 by macbookpro        #+#    #+#             */
/*   Updated: 2023/12/28 15:41:10 by macbookpro       ###   ########.fr       */
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
	pthread_mutex_lock(&info->time);
	philo->last_eat = get_timenow();
	pthread_mutex_unlock(&info->time);
	move_time(philo, info, info->time_to_eat);
	philo->count++;
	// if (philo->count >= info->num_of_eat && philo->eat_end == 0)
	// 	philo->eat_end = 1;
	pthread_mutex_unlock(&info->forks[philo->right]);
	pthread_mutex_unlock(&info->forks[philo->left]);
	// philo_print(philo, info, 3);
	// move_time(philo, info, info->time_to_sleep);
}

void	*philo_func(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->num % 2 == 0)
	{
		// philo_print(philo, info, 3);
		// move_time(philo, info, info->time_to_eat);
		usleep(100);
	}
	while (info->simulation_end != 1)
	{
		philo_eat(philo, info);
		if (philo->count == info->num_of_eat)
		{
			info->eat_end++;
			return (0);
		}
		philo_print(philo, info, 3);
		move_time(philo, info, info->time_to_sleep);
		// philo_print(philo, info, 4);
	}
	return (0);
}

int	monitoring(t_philo *philos, t_info *info)
{
	int	i;
	int	count;

	while (info->simulation_end == 0)
	{
		i = 0;
		count = 0;
		if (info->num_of_eat != -1 && count == info->num_of_philo)
		{
			info->simulation_end = 1;
			return (0);
		}
		while (i < info->num_of_philo)
		{
			if (check_die(&philos[i], info) == 1)
			{
				info->simulation_end = 1;
				pthread_mutex_unlock(&info->printer);
				return (1);
			}
			i++;
		}
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
		philos[i].last_eat = get_timenow();
		pthread_create(&philos[i].thread, NULL, philo_func, &philos[i]);
		i++;
	}
	monitoring(philos, info);
	i = 0;
	while (i < info->num_of_philo)
		pthread_join(philos[i++].thread, NULL);
	return (0);
}
