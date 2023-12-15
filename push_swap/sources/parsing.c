/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:44:52 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/15 21:38:34 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_digit(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (is_sign(str[i]))
			i++;
		if (ft_isdigit(str[i]))
		{
			count++;
			while (str[i] && ft_isdigit(str[i]))
				i++;
		}
	}
	return (count);
}

int	get_digit_idx(char *str, int idx)
{
	int	i;

	if (str == NULL || str[idx] == 0)
		return (0);
	i = idx;
	if (str == NULL || str[i] == 0)
		return (0);
	while (str[i] && is_space(str[i]))
		i++;
	if (is_sign(str[i]))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

t_data	*new_data(long long num, long long idx)
{
	t_data	*new;

	if (num < INT_MIN || num > INT_MAX)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	new = (t_data *)ft_calloc(1, sizeof(t_data));
	new->num = num;
	new->idx = idx;
	new->base3 = NULL;
	return (new);
}

// iter[3] : i, j, k, idx
t_data	**parse_argv(t_info *info)
{
	t_data	**result;
	int		iter[4];
	int		count;

	result = (t_data **)ft_calloc(info->size + 2, sizeof(t_data *));
	if (result == NULL)
		exit(EXIT_FAILURE);
	iter[0] = 1;
	iter[2] = 1;
	while (iter[2] < info->argc)
	{
		count = count_digit(info->argv[iter[2]]);
		iter[1] = 0;
		iter[3] = 0;
		while (iter[1] < count)
		{
			result[iter[0] + iter[1]] = \
			new_data(ft_atoi(info->argv[iter[2]] + iter[3]), -1);
			iter[3] = get_digit_idx(info->argv[iter[2]], iter[3]);
			iter[1]++;
		}
		iter[2]++;
		iter[0] += iter[1];
	}
	return (result);
}
