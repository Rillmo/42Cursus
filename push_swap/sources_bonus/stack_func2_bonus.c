/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:41:09 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/16 16:17:37 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_info *info, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (print)
		ft_printf("ra\n");
	if (get_stacksize(info->a) <= 1)
		return ;
	first = info->a;
	last = get_lastnode(info->a);
	info->a = first->next;
	last->next = first;
	first->next = NULL;
}

void	rb(t_info *info, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (print)
		ft_printf("rb\n");
	if (get_stacksize(info->b) <= 1)
		return ;
	first = info->b;
	last = get_lastnode(info->b);
	info->b = first->next;
	last->next = first;
	first->next = NULL;
}

void	rra(t_info *info, int print)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*cur;

	if (print)
		ft_printf("rra\n");
	if (get_stacksize(info->a) <= 1)
		return ;
	first = info->a;
	last = get_lastnode(info->a);
	cur = first;
	while (cur->next->next)
		cur = cur->next;
	cur->next = NULL;
	last->next = first;
	info->a = last;
}

void	rrb(t_info *info, int print)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*cur;

	if (print)
		ft_printf("rrb\n");
	if (get_stacksize(info->b) <= 1)
		return ;
	first = info->b;
	last = get_lastnode(info->b);
	cur = first;
	while (cur->next->next)
		cur = cur->next;
	cur->next = NULL;
	last->next = first;
	info->b = last;
}
