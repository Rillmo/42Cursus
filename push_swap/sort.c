/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:15:05 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/14 21:29:32 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_a(t_info *info, int print)
{
	t_stack	*cur;

	if (info->b == NULL)
		return ;
	cur = info->b;
	while (cur)
	{
		pa(info, print);
		ra(info, print);
		cur = info->b;
	}
}

int	is_sorted(t_info *info)
{
	t_stack	*cur;
	int		num;

	cur = info->a;
	while (cur)
	{
		num = cur->data->num;
		if (cur->next && num > cur->next->data->num)
			return (0);
		cur = cur->next;
	}
	return (1);
}

/*
	[0]: pb
	[1]: pb rb
	[2]: ra
*/
void	atob(t_info *info, int radix, int print)
{
	int	i;

	i = 1;
	while (info->a && i <= info->size)
	{
		if (info->a->data->base3[radix] == '0')
			pb(info, print);
		else if (info->a->data->base3[radix] == '1')
		{
			pb(info, print);
			rb(info, print);
		}
		else if (info->a->data->base3[radix] == '2')
			ra(info, print);
		i++;
	}
	while (info->a)
		pb(info, print);
}

/*
	[0]: pa
	[1]: pa ra
	[2]: rb
*/
void	btoa(t_info *info, int radix, int print)
{
	int		i;

	i = 1;
	while (i <= info->size && info->b)
	{
		if (info->b->data->base3[radix] == '0')
			pa(info, print);
		else if (info->b->data->base3[radix] == '1')
		{
			pa(info, print);
			ra(info, print);
		}
		else if (info->b->data->base3[radix] == '2')
			rb(info, print);
		i++;
	}
	while (info->b)
		pa(info, print);
}

void	sort_3base(t_info *info, int print)
{
	int	radix;

	radix = info->max_len - 1;
	while (radix >= 0)
	{
		if (info->b == NULL)
			atob(info, radix, print);
		else
			btoa(info, radix, print);
		radix--;
	}
}
