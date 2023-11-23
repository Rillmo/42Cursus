/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:46:42 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/23 21:53:06 by junkim2          ###   ########.fr       */
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
	return (cpy);
}

void	free_helper(void *data)
{
	free(data);
}

int	err_handler(t_mlx *mlx, char *err_message)
{
	ft_lstclear(&(mlx->heap), &free_helper);
	mlx->width = 0;
	mlx->height = 0;
	mlx->cat_loc.x = 0;
	mlx->cat_loc.y = 0;
	mlx->map = 0;
	mlx->log = 0;
	mlx->tuna_count = 0;
	printf("Error\n");
	printf("=== %s ===\n", err_message);
	return (_ERROR);
}

/*	if content is null (error occurs) : call error_handler and return NULL
	if content is not null (no error) : add to heap,tosave and return 1 */
int	check_err(t_mlx *mlx, void *content, char *err_message, char **tosave)
{
	t_list	*new;

	new = ft_lstnew(content);
	ft_lstadd_front(&(mlx->heap), new);
	if (content == NULL)
	{
		err_handler(mlx, err_message);
		return (_ERROR);
	}
	*tosave = content;
	return (1);
}
