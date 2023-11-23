/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:06:42 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/23 22:16:30 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	reset_mlx(t_mlx *mlx)
{
	mlx->heap = NULL;
	mlx->width = 0;
	mlx->height = 0;
	mlx->cat_loc.x = 0;
	mlx->cat_loc.y = 0;
	mlx->map = NULL;
	mlx->log = 0;
	mlx->tuna_count = 0;
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	int			fd;

	reset_mlx(&mlx);
	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("[ERROR]");
		return (0);
	}
	mlx.mlx_ptr = mlx_init();
	if (read_map(&mlx, fd) == _ERROR)
		return (0);
	set_image(&mlx);
	render_map(&mlx);
	mlx_hook(mlx.win_ptr, KEY_PRESS, 0, &key_event, &mlx);
	mlx_loop(mlx.mlx_ptr);
	close(fd);
	return (0);
}
