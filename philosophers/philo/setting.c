/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:54:00 by junkim2           #+#    #+#             */
/*   Updated: 2024/01/17 20:31:53 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_mutex(t_info *info)
{
	int	i;

	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (info->forks == NULL)
		return (_ERROR);
	info->lasteat = malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (info->lasteat == NULL)
		return (_ERROR);
	i = 0;
	while (i < info->num_of_philo)
	{
		if (pthread_mutex_init(&(info->forks[i]), NULL) != 0)
			return (_ERROR);
		if (pthread_mutex_init(&(info->lasteat[i]), NULL) != 0)
			return (_ERROR);
		i++;
	}
	if (pthread_mutex_init(&(info->printer), NULL) != 0)
		return (_ERROR);
	if (pthread_mutex_init(&(info->end), NULL) != 0)
		return (_ERROR);
	if (pthread_mutex_init(&(info->eatend), NULL) != 0)
		return (_ERROR);
	return (0);
}

int	set_info(t_info *info, int argc, char **argv)
{
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc > 5)
	{
		info->num_of_eat = ft_atoi(argv[5]);
		if (info->num_of_eat == 0)
			return (_ERROR);
	}
	else
		info->num_of_eat = -1;
	info->simulation_end = 0;
	info->eat_end = 0;
	info->start_time = get_timenow();
	if (set_mutex(info) == _ERROR)
	{
		destroy_all(NULL, info);
		return (_ERROR);
	}
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
