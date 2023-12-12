/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:30:13 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/12 23:17:28 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack(t_info *info)
{
	int	i;

	i = info->argc - 1;
	while (i >= 1)
		stack_addfront(&(info->a), parse_data(info->argv[i--]));
}

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

void	re_indexing(t_info *info)
{
	t_stack		*cur;
	long long	*tmp;
	int			i;

	tmp = (long long *)ft_calloc(get_stacksize(info->a) + 1, sizeof(long long));
	if (tmp == NULL)
		exit(EXIT_FAILURE);
	cur = info->a;
	i = 0;
	while (cur)
	{
		tmp[i++] = stack_delfirst(&cur)->idx;
		printf("%p %lld\n", info->a, info->a->data->idx);
	}
	int j= 0;
	while (tmp[j])
		printf("%lld\n", tmp[j++]);
	set_stack(info);
	print_(info);
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
	sort_3base(info, 0);
	print_(info);
	move_to_a(info);
	re_indexing(info);
	
	// sort_3base(info, 1);
	// print_(info);
}

int	main(int argc, char **argv)
{
	t_info	info;

	info.argc = argc;
	info.argv = argv;
	set_stack(&info);
	indexing(&(info.a), argc);
	conv_3base(info.a);
	push_swap(&info);
	// print_(&info);
	return (0);
}
