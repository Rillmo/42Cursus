/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:43:56 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/22 21:59:58 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>

//========
#include <stdio.h>
//=========

# define _ERROR 0
# define BUFF_SIZE 1000
# define BLOCK_SIZE 50
# define KEY_PRESS 2
# define KEYCODE_UP 126
# define KEYCODE_DOWN 125
# define KEYCODE_LEFT 123
# define KEYCODE_RIGHT 124
# define KEYCODE_ESC 53

typedef struct s_location
{
	int	x;
	int	y;
}	t_location;

typedef struct s_imgpack
{
	int		width;
	int		height;
	void	*tile;
	void	*wall;
	void	*tuna;
	void	*exit;
	void	*cat[4][4];
}	t_imgpack;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	t_imgpack	imgpack;
	t_location	cat_loc;
	char		**map;
	int			move_log;
}	t_mlx;


int		error_handler(char *tofree1, char *tofree2);
void	set_image(t_mlx *mlx);
void	render_map(t_mlx *mlx);
int		key_event(int keycode, t_mlx *mlx);
int		read_map(t_mlx *mlx, int fd);
void	render_sprite(t_mlx *mlx, t_imgpack imgpack, t_location loc);

#endif
