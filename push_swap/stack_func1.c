/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:29:24 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/12 23:24:18 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info, int print)
{
	t_stack	*first;
	t_stack	*second;
	t_data	*tmp;

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
	t_data	*tmp;

	if (print)
		ft_printf("sb\n");
	if (get_stacksize(info->b) <= 1)
		return ;
	first = info->b;
	second = info->b;
	tmp = first->data;
	first->data = second->data;
	second->data = tmp;
}

void	pa(t_info *info, int print)
{
	t_data	*tmp;

	if (print)
		ft_printf("pa\n");
	if (info->b == NULL)
		return ;
	tmp = stack_delfirst(&(info->b));
	stack_addfront(&(info->a), tmp);
}

void	pb(t_info *info, int print)
{
	t_data	*tmp;

	if (print)
		ft_printf("pb\n");
	if (info->a == NULL)
		return ;
	print_(info);
	tmp = stack_delfirst(&(info->a));
	printf("%p %lld\n", tmp, tmp->idx);
	print_(info);
	stack_addfront(&(info->b), tmp);
}
