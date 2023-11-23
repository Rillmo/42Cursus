/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:46:42 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/23 14:47:22 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**copy_map(char **map, int height)
{
	int		i;
	char	**cpy;

	cpy = (char **)ft_calloc(height + 1, sizeof(char *));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		cpy[i] = ft_strdup(map[i]);
		if (cpy == NULL)
			return (NULL);
		i++;
	}
	// cpy[i] = 0;
	return (cpy);
}

int	error_handler(char *tofree1, char *tofree2)
{
	free(tofree1);
	free(tofree2);
	write(1, "Error\n", 6);
	return (_ERROR);
}
