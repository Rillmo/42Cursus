/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:11:37 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/15 19:50:25 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	int		i;

	cur = info->a;
	i = 1;
	printf(" A\t| ");
	while (cur && i <= info->size)
	{
		printf("(%lld|%s)(%p) ", cur->data->idx, cur->data->base3, cur->data);
		cur = cur->next;
	}
	printf("\n B\t| ");
	cur = info->b;
	i = 1;
	while (cur && i <= info->size)
	{
		printf("(%lld|%s) ", cur->data->idx, cur->data->base3);
		cur = cur->next;
	}
	printf("\n origin\t| ");
	i = 1;
	while (i <= info->size)
	{
		printf("(%lld|%s)(%p) ", info->origin[i]->idx, info->origin[i]->base3, info->origin[i]);
		i++;
	}
	printf("\n sorted\t| ");
	i = 1;
	while (info->sorted && i <= info->size)
	{
		if (info->sorted[i])
			printf("(%lld|%s)(%p) ", info->sorted[i]->idx, info->sorted[i]->base3, info->sorted[i]);
		i++;
	}
	printf("\n");
}
