/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:20:15 by macbookpro        #+#    #+#             */
/*   Updated: 2023/12/27 21:45:00 by junkim2          ###   ########.fr       */
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
	move_time(philo, info, info->time_to_eat);
	philo->count++;
	if (philo->count >= info->num_of_eat)
		philo->eat_end = 1;
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
		philo_print(philo, info, 3);
		move_time(philo, info, info->time_to_sleep);
	}
	return (0);
}

int	monitoring(t_philo *philos, t_info *info)
{
	int	i;
	int	count;

	while (1)
	{
		i = 0;
		count = 0;
		while (i < info->num_of_philo)
		{
			if (check_die(&philos[i], info) == 1)
			{
				// pthread_mutex_unlock(&info->printer);
				info->simulation_end = 1;
				return (1);
			}
			if (philos[i].eat_end == 1)
				count++;
			i++;
		}
		if (info->num_of_eat != -1 && count == info->num_of_philo)
		{
			info->simulation_end = 1;
			return (0);
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
	if (monitoring(philos, info) == 1)
		pthread_mutex_unlock(&info->printer);
	i = 0;
	while (i < info->num_of_philo)
		pthread_join(philos[i++].thread, NULL);
	return (0);
}
