/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:06:05 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/22 22:20:47 by junkim2          ###   ########.fr       */
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
		info->num_of_times_each_philo_must_eat = ft_atoi(argv[5]);
}

void	*phlio_do_something(void *arg)
{
	(void)arg;
	printf("I'am 신뢰에요\n");
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_info		info;
	pthread_t	phlio;

	set_info(&info, argc, argv);
	pthread_create(&phlio, NULL, &phlio_do_something, NULL);
	// pthread_detach(phlio);
}
