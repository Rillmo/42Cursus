/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:54:00 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/23 16:07:13 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_info(t_info *info, int argc, char **argv)
{
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc > 5)
		info->num_of_eat = ft_atoi(argv[5]);
}

void	set_philo(t_info *info)
{
	int	i;

	info->philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (info->philos == NULL)
		return ;
	i = 0;
	while (i < info->num_of_philo)
	{
		info->philos[i].num = i + 1;
		i++;
	}
}
