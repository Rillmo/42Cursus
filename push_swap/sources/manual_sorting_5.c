/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sorting_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:39:08 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/15 15:26:32 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort5_12(t_info *info)
{
	t_stack	*cur;

	cur = info->a;
	while (cur)
	{
		if (cur->data->idx == 2)
			pb(info, 1);
		else if (cur->data->idx == 1)
		{
			pb(info, 1);
			if (get_stacksize(info->b) != 0)
				rb(info, 1);
		}
		else
			ra(info, 1);
		cur = info->a;
		if (get_stacksize(info->b) == 2)
			return ;
	}
}

static void	sort5_345(t_info *info)
{
	t_stack	*cur;

	cur = info->a;
	if (cur->data->idx == 3)
	{
		rra(info, 1);
		sa(info, 1);
	}
	else if (cur->data->idx == 4)
	{
		if (cur->next->data->idx == 5)
			rra(info, 1);
		else
			sa(info, 1);
	}
	else
	{
		if (cur->next->data->idx == 3)
			ra(info, 1);
		else
		{
			ra(info, 1);
			sa(info, 1);
		}
	}
}

void	sort5(t_info *info)
{
	t_stack	*cur;
	int		num;

	sort5_12(info);
	cur = info->a;
	while (cur)
	{
		num = cur->data->num;
		if (cur->next && num > cur->next->data->num)
		{
			sort5_345(info);
			break ;
		}
		cur = cur->next;
	}
	pa(info, 1);
	pa(info, 1);
}
