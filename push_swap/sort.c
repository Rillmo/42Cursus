/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:15:05 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/11 22:37:16 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_only2remain(t_stack *stack, int radix)
{
	t_stack	*cur;

	cur = stack;
	while (cur)
	{
		if (cur->data->base3[radix] != 2)
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
void	atob(t_info *info, int radix)
{
	t_stack	*cur;

	cur = info->a;
	while (check_only2remain(info->a, radix))
	{
		print_(info);
		if (cur->data->base3[radix] == '0')
			pb(info);
		else if (cur->data->base3[radix] == '1')
		{
			pb(info);
			rb(info);
		}
		else
			ra(info);
		cur = info->a;
	}
	cur = info->a;
	while (cur)
	{
		pb(info);
		cur = info->a;
	}
	print_(info);
}

void	btoa(t_info *info, int radix)
{
	t_stack	*cur;

	cur = info->b;
	while (check_only2remain(info->a, radix))
	{
		print_(info);
		if (cur->data->base3[radix] == '0')
			pb(info);
		else if (cur->data->base3[radix] == '1')
		{
			pb(info);
			rb(info);
		}
		else
			ra(info);
		cur = info->b;
	}
	print_(info);
	cur = info->b;
	while (cur)
	{
		pa(info);
		cur = info->b;
	}
}

void	sort_3base(t_info *info)
{
	int		radix;

	radix = info->max_len - 1;
	while (radix >= 0)
	{
		if (info->b == NULL)
			atob(info, radix);
		else
			btoa(info, radix);
		radix--;
	}
}
