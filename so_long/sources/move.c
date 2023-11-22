/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:47:05 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/22 22:45:52 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	key_up(t_mlx *mlx, t_imgpack imgpack)
{
	int	x;
	int	y;
	int	gx;
	int	gy;

	x = mlx->cat_loc.x;
	y = mlx->cat_loc.y;
	gx = x * imgpack.width;
	gy = y * imgpack.width;

	if (0 > y - 1 || mlx->map[y - 1][x] == '1')
		return ;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	imgpack.cat[0][mlx->move_log % 4], gx, (y - 1) * BLOCK_SIZE);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, imgpack.tile, gx, gy);
	mlx->cat_loc.y--;
	mlx->move_log++;
	printf("move : %d\n", mlx->move_log);
}

void	key_down(t_mlx *mlx, t_imgpack imgpack)
{
	int	x;
	int	y;
	int	gx;
	int	gy;

	x = mlx->cat_loc.x;
	y = mlx->cat_loc.y;
	gx = x * imgpack.width;
	gy = y * imgpack.width;

	if (mlx->height < y + 1 || mlx->map[y + 1][x] == '1')
		return ;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	imgpack.cat[1][mlx->move_log % 4], gx, (y + 1) * BLOCK_SIZE);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, imgpack.tile, gx, gy);
	mlx->cat_loc.y++;
	mlx->move_log++;
	printf("move : %d\n", mlx->move_log);
}

void	key_left(t_mlx *mlx, t_imgpack imgpack)
{
	int	x;
	int	y;
	int	gx;
	int	gy;

	x = mlx->cat_loc.x;
	y = mlx->cat_loc.y;
	gx = x * imgpack.width;
	gy = y * imgpack.width;

	if (0 > x - 1 || mlx->map[y][x - 1] == '1')
		return ;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	imgpack.cat[2][mlx->move_log % 4], (x - 1) * BLOCK_SIZE, y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, imgpack.tile, gx, gy);
	mlx->cat_loc.x--;
	mlx->move_log++;
	printf("move : %d\n", mlx->move_log);
}

void	key_right(t_mlx *mlx, t_imgpack imgpack)
{
	int	x;
	int	y;
	int	gx;
	int	gy;

	x = mlx->cat_loc.x;
	y = mlx->cat_loc.y;
	gx = x * imgpack.width;
	gy = y * imgpack.width;

	if (mlx->width < x + 1 || mlx->map[y][x + 1] == '1')
		return ;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	imgpack.cat[3][mlx->move_log % 4], (x + 1) * BLOCK_SIZE, y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, imgpack.tile, gx, gy);
	mlx->cat_loc.x++;
	mlx->move_log++;
	printf("move : %d\n", mlx->move_log);
}

int	key_event(int keycode, t_mlx *mlx)
{
	if (keycode == KEYCODE_UP)
		key_up(mlx, mlx->imgpack);
	else if (keycode == KEYCODE_DOWN)
		key_down(mlx, mlx->imgpack);
	else if (keycode == KEYCODE_LEFT)
		key_left(mlx, mlx->imgpack);
	else if (keycode == KEYCODE_RIGHT)
		key_right(mlx, mlx->imgpack);
	else if (keycode == KEYCODE_ESC)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	// printf("keycode : %d\n", keycode);
	return (0);
}
