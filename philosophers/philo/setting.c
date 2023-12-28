/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:54:00 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/28 15:42:35 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_mutex(t_info *info)
{
	int	i;

	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (info->forks == NULL)
		return (_ERROR);
	i = 0;
	while (i < info->num_of_philo)
		pthread_mutex_init(&(info->forks[i++]), NULL);
	pthread_mutex_init(&(info->printer), NULL);
	pthread_mutex_init(&(info->time), NULL);
	return (0);
}

int	set_info(t_info *info, int argc, char **argv)
{
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc > 5)
		info->num_of_eat = ft_atoi(argv[5]);
	else
		info->num_of_eat = -1;
	info->simulation_end = 0;
	info->eat_end = 0;
	info->start_time = get_timenow();
	if (set_mutex(info) == _ERROR)
		return (_ERROR);
	return (0);
}

int	set_philo(t_philo **philos, t_info *info)
{
	int		i;

	*philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (*philos == NULL)
		return (_ERROR);
	i = 0;
	while (i < info->num_of_philo)
	{
		(*philos)[i].num = i;
		(*philos)[i].left = i;
		(*philos)[i].right = (i + 1) % info->num_of_philo;
		(*philos)[i].info = info;
		(*philos)[i].last_eat = 0;
		(*philos)[i].count = 0;
		i++;
	}
	return (0);
}
