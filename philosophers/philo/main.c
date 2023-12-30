/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:06:05 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/30 01:25:38 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_leak(void)
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_info	info;

	// atexit(check_leak);
	if (argc < 5 || argc > 6)
		return (1);
	if (set_info(&info, argc, argv) == _ERROR)
		return (_ERROR);
	if (set_philo(&philos, &info) == _ERROR)
		return (_ERROR);
	philo_thread(philos);
	return (0);
}
