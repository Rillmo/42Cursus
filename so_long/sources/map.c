/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:12:30 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/23 13:43:44 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	read_map(t_mlx *mlx, int fd)
{
	char	*buff;
	char	*line;

	buff = get_next_line(fd);
	if (buff == NULL)
		return (_ERROR);
	mlx->width = ft_strlen(buff) - 1;
	line = "";
	while (buff != NULL)
	{
		mlx->height++;
		line = ft_strjoin(line, buff);
		buff = get_next_line(fd);
	}
	mlx->map = ft_split(line, '\n');
	return (1);
}
