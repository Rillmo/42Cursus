/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:20:15 by macbookpro        #+#    #+#             */
/*   Updated: 2023/12/25 12:52:34 by macbookpro       ###   ########.fr       */
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

void    *philo_func(void *arg)
{
    t_philo	*philo;
    t_info	*info;
	long long	start_time;

    philo = (t_philo *)arg;
	info = philo->info;
	start_time = get_timenow();
	printf("[%lld]\t| %d번 훈련병 식사준비 끝\n", get_timenow() - start_time, philo->num);
	while (get_timenow() - start_time < info->time_to_eat)
		usleep(100);
	printf("[%lld]\t| %d번 훈련병 식사 끝\n", get_timenow() - start_time, philo->num);
	return (0);
}

int philo_thread(t_philo *philos)
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