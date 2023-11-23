/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:12:30 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/23 14:58:48 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	dfs(char **map, int i, int j)
{
	const int	*dx = {0, 0, -1, 1};
	const int	*dy = {-1, 1, 0, 0};
	int			i;

	i = 0;
	while (i < 4)
	{
		if (map[dy[i]][dx[i]] == 'E')
			return (1);
		else if (map[dy[i]][dx[i]] == '0')
			map[dy[i]][dx[i]] = '1';
		else if (map[dy[i]])
	}
}

int	check_map(t_mlx *mlx)
{
	char	**cpy;
	int		i;
	int		j;

	cpy = copy_map(mlx->map, mlx->height);
	i = 0;
	while (i < mlx->height)
	{
		j = 0;
		while (j < mlx->width)
		{
			if (mlx->map[i][j] == 'P')
			{
				
			}
			j++;
		}
		i++;
	}
	// for(int i=0; i<mlx->height; i++)
	// {
	// 	for(int j=0; j<mlx->width; j++)
	// 		printf("%c", mlx->map[i][j]);
	// 	printf("\n");
	// }
	// printf("\n");
	// for(int i=0; i<mlx->height; i++)
	// {
	// 	for(int j=0; j<mlx->width; j++)
	// 		printf("%c", cpy[i][j]);
	// 	printf("\n");
	// }
	return (0);
}

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
	check_map(mlx);
	return (1);
}
