/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:42:44 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/15 13:23:52 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	conv_3base(t_info *info, t_data **arr)
{
	int		i;
	int		j;
	char	*result;
	int		n;

	i = 1;
	while (i <= info->size)
	{
		result = (char *)ft_calloc(info->max_len + 1, sizeof(char));
		if (result == NULL)
			exit(EXIT_FAILURE);
		n = arr[i]->idx;
		j = info->max_len - 1;
		while (j >= 0)
		{
			result[j] = n % 3 + '0';
			n /= 3;
			j--;
		}
		arr[i]->base3 = result;
		i++;
	}
}

int	get_3base_len(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 3;
		len++;
	}
	return (len);
}

int	get_max_len(t_data **arr, int size)
{
	int	max;
	int	len;
	int	i;

	max = -1;
	i = 1;
	while (i < size)
	{
		len = get_3base_len(arr[i]->idx);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}
