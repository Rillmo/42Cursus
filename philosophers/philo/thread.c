/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:20:15 by macbookpro        #+#    #+#             */
/*   Updated: 2024/01/17 17:42:07 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->forks[philo->left]);
	philo_print(philo, info, 1);
	pthread_mutex_lock(&info->forks[philo->right]);
	philo_print(philo, info, 1);
	philo_print(philo, info, 2);
	set_lasteat(philo, info, get_timenow());
	move_time(info, info->time_to_eat);
	pthread_mutex_unlock(&info->forks[philo->right]);
	philo->count++;
	pthread_mutex_unlock(&info->forks[philo->left]);
	return (0);
}

void	one_philo(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->forks[philo->left]);
	philo_print(philo, info, 1);
	while (get_end(info) != 1)
		usleep(100);
}

void	*philo_func(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	philo_print(philo, info, 4);
	if (info->num_of_philo == 1)
		one_philo(philo, info);
	if (philo->num % 2 == 0 && info->num_of_philo != 1)
		move_time(info, info->time_to_eat);
	set_lasteat(philo, info, get_timenow());
	while (get_end(info) != 1)
	{
		philo_eat(philo, info);
		if (philo->count == info->num_of_eat)
			set_eatend(info, 1);
		if (philo->num == info->num_of_philo - 1 && philo->count == 0)
			usleep(10);
		philo_print(philo, info, 3);
		move_time(info, info->time_to_sleep);
		philo_print(philo, info, 4);
	}
	return (0);
}

int	monitoring(t_philo *philos, t_info *info)
{
	int	i;
	int	check;

	while (get_end(info) == 0)
	{
		i = 0;
		if (info->num_of_eat != -1 && get_eatend(info) == info->num_of_philo)
		{
			set_end(info, 1);
			return (0);
		}
		while (get_end(info) != 1 && i < info->num_of_philo)
		{
			check = check_die(&philos[i], info);
			if (check == 1)
				return (1);
			else if (check == _ERROR)
				return (_ERROR);
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
	info->start_time = get_timenow();
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
