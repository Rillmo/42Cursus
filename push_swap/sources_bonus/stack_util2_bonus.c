/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:11:37 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/16 16:30:40 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
