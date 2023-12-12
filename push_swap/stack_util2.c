/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:11:37 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/12 22:49:07 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_lastnode(t_stack *stack)
{
	t_stack	*cur;

	if (stack == 0)
		return (0);
	cur = stack;
	while (cur->next != 0)
		cur = cur->next;
	return (cur);
}

int	get_stacksize(t_stack *stack)
{
	t_stack	*cur;
	int		count;

	if (stack == 0)
		return (0);
	count = 1;
	cur = stack;
	while (cur->next != 0)
	{
		count++;
		cur = cur->next;
	}
	return (count);
}

void	print_(t_info *info)
{
	t_stack	*cur;

	cur = info->a;
	printf(" A | ");
	while (cur)
	{
		printf("(%lld|%s) ", cur->data->idx, \
		cur->data->base3);
		cur = cur->next;
	}
	printf("\n B | ");
	cur = info->b;
	while (cur)
	{
		printf("(%lld|%s) ", cur->data->idx, \
		cur->data->base3);
		cur = cur->next;
	}
	printf("\n");
}
