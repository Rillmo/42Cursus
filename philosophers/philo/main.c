/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:06:05 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/23 16:06:47 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*phlio_do(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("I am %d에요\n", philo->num);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info		info;
	int			i;

	set_info(&info, argc, argv);
	set_philo(&info);
	i = 0;
	while (i < info.num_of_philo)
	{
		printf("%d\n", i);
		pthread_create(&info.philos[i].thread, NULL, \
		&phlio_do, &(info.philos[i]));
		i++;
	}
	i = 0;
	while (i < info.num_of_philo)
		pthread_join(info.philos[i++].thread, NULL);
}
