/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:46:42 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/22 21:01:37 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_handler(char *tofree1, char *tofree2)
{
	free(tofree1);
	free(tofree2);
	write(1, "Error\n", 6);
	return (_ERROR);
}
