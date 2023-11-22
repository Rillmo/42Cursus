/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:06:42 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/22 20:39:42 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	int			fd;

	mlx.mlx_ptr = mlx_init();
	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	read_map(&mlx, fd);
	set_image(&mlx);
	render_map(&mlx);
	mlx_hook(mlx.win_ptr, KEY_PRESS, 0, &key_event, &mlx);
	mlx_loop(mlx.mlx_ptr);
	close(fd);
	return (0);
}
