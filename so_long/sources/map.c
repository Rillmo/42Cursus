/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:12:30 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/23 22:16:52 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int	check_valid_path(char **map, int y, int x)
// {
// 	const int	*dx = {0, 0, -1, 1};
// 	const int	*dy = {-1, 1, 0, 0};
// 	int			i;
// 	char		now;

// 	i = 0;	// cat = map[1][1] = 'P'
// 	while (i < 4)		// i = 0 -> (up) -> now = map[0][1] -> 
// 	{
// 		now = map[y + dy[i]][x + dx[i]];
// 		dfs(map, y + i, x + i);
// 	}
// 	return (dfs(map, i, j))
// }

// check map covered by '1'
int	check_wall(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if ((i == 0 || i == height - 1) && map[i][j] != '1')
				return (_ERROR);
			if ((j == 0 || j == width - 1) && map[i][j] != '1')
				return (_ERROR);
			j++;
		}
		i++;
	}
	return (1);
}

/*	[check resources]
	resource[3] means -> 0:E, 1:C, 2:P */
int	check_resources(char **map, int height, int width)
{
	int	i;
	int	j;
	int	resources[3];

	ft_bzero(resources, 3);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'E')
				resources[0]++;
			else if (map[i][j] == 'C')
				resources[1]++;
			else if (map[i][j] == 'P')
				resources[2]++;
			j++;
		}
		i++;
	}
	if (resources[0] != 1 || resources[1] < 1 || resources[2] != 1)
		return (_ERROR);
	return (1);
}

/*	1. rectangle check 				...ok
	2. wall check					...ok
	3. valid path check				...
	4. resource check : 1E, 1C, 1P	...ok */
int	check_map(t_mlx *mlx)
{
	char	**cpy;
	int		i;

	cpy = copy_map(mlx->map, mlx->height);
	if (cpy == NULL)
		return (err_handler(mlx, "(f)copy_map error"));
	i = 0;
	while (mlx->map[i] != 0)
	{
		if ((int)ft_strlen(mlx->map[i]) != mlx->width)
			return (err_handler(mlx, "map is not rectangle"));
		i++;
	}
	if (!check_resources(mlx->map, mlx->height, mlx->width))
		return (err_handler(mlx, "invalid amount of R or C or P"));
	if (!check_wall(mlx->map, mlx->height, mlx->width))
		return (err_handler(mlx, "map is not covered by wall"));
	return (1);
}

// read map to array
int	read_map(t_mlx *mlx, int fd)
{
	char	*buff;
	char	*line;

	if (!check_err(mlx, get_next_line(fd), "File read error", &buff))
		return (_ERROR);
	mlx->width = ft_strlen(buff) - 1;
	line = "";
	while (buff != NULL)
	{
		mlx->height++;
		if (!check_err(mlx, ft_strjoin(line, buff), "(f)strjoin error", &line))
			return (_ERROR);
		// printf("line:%s\nbuff:%s\n", line, buff);
		buff = get_next_line(fd);
	}
	mlx->map = ft_split(line, '\n');
	if (mlx->map == NULL)
		return (err_handler(mlx, "(f)ft_split error"));
	if (!check_map(mlx))
		return (_ERROR);
	return (1);
}
