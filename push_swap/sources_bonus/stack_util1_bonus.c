/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:51:12 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/16 15:05:31 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_stack	*get_newnode(int data)
{
	t_stack	*new;

	new = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (new == 0)
		exit(EXIT_FAILURE);
	new->data = data;
	new->next = 0;
	return (new);
}

void	stack_addfront(t_stack **stack, int data)
{
	t_stack	*new;

	new = get_newnode(data);
	if (*stack == 0)
	{
		*stack = new;
		return ;
	}
	new->next = *(stack);
	*stack = new;
}

int	stack_delfirst(t_stack **stack)
{
	t_stack	*remove;
	int		result;

	remove = *stack;
	result = remove->data;
	*stack = remove->next;
	free(remove);
	remove = 0;
	return (result);
}
