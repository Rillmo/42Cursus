/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:29:24 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/16 16:10:45 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	sa(t_info *info, int print)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if (print)
		ft_printf("sa\n");
	if (get_stacksize(info->a) <= 1)
		return ;
	first = info->a;
	second = info->a->next;
	tmp = first->data;
	first->data = second->data;
	second->data = tmp;
}

void	sb(t_info *info, int print)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if (print)
		ft_printf("sb\n");
	if (get_stacksize(info->b) <= 1)
		return ;
	first = info->b;
	second = info->b->next;
	tmp = first->data;
	first->data = second->data;
	second->data = tmp;
}

void	pa(t_info *info, int print)
{
	t_stack	*tmp;

	if (print)
		ft_printf("pa\n");
	if (info->b == 0)
		return ;
	tmp = info->b;
	info->b = info->b->next;
	tmp->next = info->a;
	info->a = tmp;
}

void	pb(t_info *info, int print)
{
	t_stack	*tmp;

	if (print)
		ft_printf("pb\n");
	if (info->a == 0)
		return ;
	tmp = info->a;
	info->a = info->a->next;
	tmp->next = info->b;
	info->b = tmp;
}
