/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:08:50 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/14 22:35:08 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort4(t_info *info)
{
	t_stack	*cur;

	cur = info->a;
	if (cur->data->idx == 1 || cur->data->idx == 2)
	{
		if (cur->data->idx == 1)
		{
			pb(info, 1);
			rb(info, 1);
		}
		else
			pb(info, 1);
	}
	else
	{
		if (cur->data->idx == 4)
			sa(info, 1);
	}
	pa(info, 1);
	pa(info, 1);
}

void	sort3(t_info *info)
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

void	man_sorting(t_info *info)
{
	if (info->size == 2)
		sa(info, 1);
	else if (info->size == 3)
		sort3(info);
	else if (info->size == 4)
		sort4(info);
	exit(0);
}
