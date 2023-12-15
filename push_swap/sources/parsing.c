/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:44:52 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/15 13:23:52 by junkim2          ###   ########.fr       */
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

t_data	**parse_argv(t_info *info)
{
	t_data	**result;
	int		i;
	int		j;
	int		idx;
	int		count;
	int		k;

	result = (t_data **)ft_calloc(info->size + 2, sizeof(t_data *));
	if (result == NULL)
		exit(EXIT_FAILURE);
	i = 1;
	k = 1;
	while (k < info->argc)
	{
		count = count_digit(info->argv[k]);
		j = 0;
		idx = 0;
		while (j < count)
		{
			result[i + j] = new_data(ft_atoi(info->argv[k] + idx), -1);
			idx = get_digit_idx(info->argv[k], idx);
			j++;
		}
		k++;
		i += j;
	}
	return (result);
}
