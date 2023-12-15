/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:38:46 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/14 23:23:13 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/includes/push_swap.h"

void	load_to_a(t_info *info, t_data **arr)
{
	int	i;

	i = info->size;
	while (i >= 1)
	{
		stack_addfront(&(info->a), arr[i]);
		i--;
	}
}

void	indexing(t_data **arr, int size)
{
	int		min_idx;
	int		min;
	int		i;
	int		j;

	min = 0;
	i = 1;
	while (i <= size)
	{
		min = INT_MAX;
		j = 1;
		while (j <= size)
		{
			if (min >= arr[j]->num && arr[j]->idx == -1)
			{
				min_idx = j;
				min = arr[j]->num;
			}
			j++;
		}
		arr[min_idx]->idx = i;
		i++;
	}
}

void	set_origin(t_info *info, int argc, char **argv)
{
	int	i;
	int	count;

	info->argc = argc;
	info->argv = argv;
	info->a = NULL;
	info->b = NULL;
	i = 1;
	count = 0;
	while (i < argc)
		count += count_digit(argv[i++]);
	info->size = count;
	info->origin = parse_argv(info);
	indexing(info->origin, info->size);
	info->max_len = get_max_len(info->origin, info->size);
	conv_3base(info, info->origin);
	load_to_a(info, info->origin);
}

void	save_to_sorted(t_info *info)
{
	int		i;
	int		idx;
	char	*base3;

	info->sorted = (t_data **)ft_calloc(info->size + 2, sizeof(t_data *));
	if (info->sorted == NULL)
		exit(EXIT_FAILURE);
	i = 1;
	while (info->a)
	{
		info->sorted[i] = stack_delfirst(&(info->a));
		i++;
	}
	i = 1;
	while (i <= info->size)
	{
		idx = info->sorted[info->origin[i]->idx]->idx;
		base3 = info->sorted[info->origin[i]->idx]->base3;
		info->origin[i]->base3 = info->sorted[info->origin[i]->idx]->base3;
		i++;
	}
	load_to_a(info, info->origin);
}
