/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:51:12 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/12 23:32:38 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_newnode(t_data *data)
{
	t_stack	*new;

	new = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (new == 0)
		return (0);
	new->data = data;
	new->next = 0;
	return (new);
}

void	stack_addfront(t_stack **stack, t_data *data)
{
	t_stack	*new;

	new = get_newnode(data);
	new->next = *stack;
	*stack = new;
}

void	stack_addback(t_stack **stack, t_data *data)
{
	t_stack	*new;
	t_stack	*last;

	last = get_lastnode(*stack);
	new = get_newnode(data);
	if (last == 0)
	{
		*stack = new;
		return ;
	}
	new->next = new;
}

t_data	*stack_delfirst(t_stack **stack)
{
	t_stack	*remove;
	t_data	*result;

	remove = *stack;
	result = (t_data *)ft_calloc(1, sizeof(t_data));
	if (result == NULL)
		return (NULL);
	result->base3 = ft_strdup(remove->data->base3);
	result->idx = remove->data->idx;
	result->num = remove->data->num;
	result->str = ft_strdup(remove->data->str);
	*stack = (*stack)->next;
	// printf("remove : %p %p\n", remove->data, *(remove->data));
	// printf("delfirst : %p %lld\n", result, result->idx);
	free(remove);
	remove = NULL;
	return (result);
}

t_data	*stack_dellast(t_stack **stack)
{
	t_stack	*remove;
	t_data	*result;

	remove = *stack;
	result = remove->data;
	*stack = (*stack)->next;
	free(remove);
	return (result);
}