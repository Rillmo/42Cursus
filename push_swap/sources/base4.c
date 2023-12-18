/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:57:02 by macbookpro        #+#    #+#             */
/*   Updated: 2023/12/18 16:14:48 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_pow(int x, int y)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (i < y)
	{
		result *= x;
		i++;
	}
	return (result);
}

void	sort_4base(t_info *info, int print)
{
	int	i;
	int	base4;

	i = 1;
	if (info->b == NULL)
		return ;
	while (info->b && i <= info->size)
	{
		base4 = ((info->b->data->base3[0] - '0') * 3 + \
			(info->b->data->base3[1] - '0')) % 4;
		if (base4 == 0)
			pa(info, print);
		else if (base4 == 1)
		{
			pa(info, print);
			ra(info, print);
		}
		else
			rb(info, print);
		i++;
	}
	while (info->b)
	{
		base4 = ((info->b->data->base3[0] - '0') * 3 + \
			(info->b->data->base3[1] - '0')) % 4;
		if (base4 == 2)
			pa(info, print);
		else if (base4 == 3)
		{
			pa(info, print);
			ra(info, print);
		}
	}
}
