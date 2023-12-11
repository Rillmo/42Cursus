/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:30:13 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/11 20:59:49 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_len(t_stack *stack)
{
	t_stack	*cur;
	int		max;
	int		len;

	cur = stack;
	max = -1;
	while (cur)
	{
		len = get_3base_len(stack->data->idx);
		if (len > max)
		{
			max = len;
		}
		cur = cur->next;
	}
	return (max);
}

/*
	1. find num that has maximum length in 3base
	2. 3base sorting
	3. re-indexing
	4. 3base sorting
*/
void	push_swap(t_info *info)
{
	info->max_len = get_max_len(info->a);
	sort_3base(info);
}

int	main(int argc, char **argv)
{
	int		i;
	t_info	info;

	i = 1;
	while (i < argc)
		stack_addfront(&(info.a), parse_data(argv[i++]));
	indexing(&(info.a), argc);
	conv_3base(info.a);
	// print_(&info);
	push_swap(&info);
	// print_(&info);
	return (0);
}
