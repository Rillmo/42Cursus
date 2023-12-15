/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:08:50 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/15 15:09:43 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort3(t_info *info)
{
	t_stack	*first;

	first = info->a;
	if (first->data->idx == 1)
	{
		rra(info, 1);
		sa(info, 1);
	}
	else if (first->data->idx == 2)
	{
		if (first->next->data->idx == 1)
			sa(info, 1);
		else
			rra(info, 1);
	}
	else
	{
		if (first->next->data->idx == 1)
			ra(info, 1);
		else
		{
			ra(info, 1);
			sa(info, 1);
		}
	}
}

static void	sort4_34(t_info *info, t_stack *cur)
{
	if (cur->data->idx == 3)
	{
		if (get_stacksize(info->b) == 2 && cur->next->data->idx == 4)
		{
			pa(info, 1);
			pa(info, 1);
		}
		else
			ra(info, 1);
	}
	else
	{
		if (get_stacksize(info->b) == 2)
			sa(info, 1);
		else
			ra(info, 1);
	}
}

static void	sort4(t_info *info)
{
	t_stack	*cur;

	cur = info->a;
	while (cur)
	{
		if (cur->data->idx == 1 && get_stacksize(info->b) != 0)
		{
			pb(info, 1);
			rb(info, 1);
		}
		else if (cur->data->idx == 1 && get_stacksize(info->b) == 0)
			pb(info, 1);
		else if (cur->data->idx == 2)
			pb(info, 1);
		else
			sort4_34(info, cur);
		if (is_sorted(info))
			exit(0);
		cur = info->a;
	}
}

void	man_sorting(t_info *info)
{
	if (info->size == 2)
		sa(info, 1);
	else if (info->size == 3)
		sort3(info);
	else if (info->size == 4)
		sort4(info);
	else
		sort5(info);
	exit(0);
}
