/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:06:05 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/30 14:46:50 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	err_handler(t_philo *philos, t_info *info)
{
	destroy_all(philos, info);
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_info	info;

	if (argc < 5 || argc > 6)
		return (_ERROR);
	if (set_info(&info, argc, argv) == _ERROR)
		return (_ERROR);
	if (set_philo(&philos, &info) == _ERROR)
		return (err_handler(philos, &info));
	if (philo_thread(philos) == _ERROR)
		return (err_handler(philos, &info));
	destroy_all(philos, &info);
	return (0);
}
