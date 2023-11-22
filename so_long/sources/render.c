/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:32:23 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/22 22:32:35 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_object(t_mlx *mlx, t_imgpack imgpack, \
						t_location loc, char object)
{
	int	x;
	int	y;

	x = loc.x * imgpack.width;
	y = loc.y * imgpack.height;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	imgpack.tile, x, y);
	if (object == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		imgpack.wall, x, y);
	else if (object == 'P')
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		imgpack.cat[0][0], x, y);
		mlx->cat_loc.x = loc.x;
		mlx->cat_loc.y = loc.y;
	}
	else if (object == 'C')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		imgpack.tuna, x + imgpack.width / 4, y + imgpack.height / 4);
	else if (object == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		imgpack.exit, x, y);
}

void	render_map(t_mlx *mlx)
{
	t_location	loc;

	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->width * BLOCK_SIZE, \
	mlx->height * BLOCK_SIZE, "game");
	loc.y = 0;
	while (loc.y < mlx->height)
	{
		loc.x = 0;
		while (loc.x < mlx->width)
		{
			render_object(mlx, mlx->imgpack, loc, mlx->map[loc.y][loc.x]);
			loc.x++;
		}
		loc.y++;
	}
}
