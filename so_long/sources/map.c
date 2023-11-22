/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:12:30 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/22 20:35:49 by junkim2          ###   ########.fr       */
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
	mlx->height = 0;
	line = "";
	while (buff != NULL)
	{
		mlx->height++;
		line = ft_strjoin(line, buff);
		buff = get_next_line(fd);
	}
	mlx->map = ft_split(line, '\n');
	// printf("width:%d heigth:%d\n", mlx->width, mlx->height);
	// for(int i=0; i<mlx->height; i++)
	// {
	// 	printf("[%d] | %s\n", i, mlx->map[i]);
	// }
	return (1);
}
