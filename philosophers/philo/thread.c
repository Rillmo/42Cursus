/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:20:15 by macbookpro        #+#    #+#             */
/*   Updated: 2023/12/24 23:49:56 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_checker(t_info *info, t_philo *philo)
{
	t_timeval	now;
	long long	elapsed_time;

	while (1)
	{
		gettimeofday(&now, NULL);
		elapsed_time = (now.tv_sec - philo->start_time.tv_sec) + \
		(now.tv_usec - philo->start_time.tv_usec) / 1000000;
		if (elapsed_time >= )
	}
}

void    *philo_func(void *arg)
{
    t_philo	*philo;
    t_info	*info;

    philo = (t_philo *)arg;
	info = philo->info;
	gettimeofday(&philo->start_time, NULL);
}

int philo_eat(t_philo *philos)
{
	int		i;
	t_info	*info;

	info = philos[i].info;
	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_create(&philos[i].thread, NULL, philo_func, &philos[i]);
		i++;
	}
	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_join(philos[i++].thread, NULL);
	}
	return (0);
}