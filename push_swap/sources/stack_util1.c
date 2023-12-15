/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:51:12 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/15 16:11:36 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*get_newnode(t_data *data)
{
	t_stack	*new;

	new = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (new == 0)
		return (0);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	stack_addfront(t_stack **stack, t_data *data)
{
	t_stack	*new;

	new = get_newnode(data);
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	new->next = *(stack);
	*stack = new;
}

t_data	*stack_delfirst(t_stack **stack)
{
	t_stack	*remove;
	t_data	*result;

	remove = *stack;
	result = remove->data;
	*stack = remove->next;
	free(remove);
	remove = NULL;
	return (result);
}
