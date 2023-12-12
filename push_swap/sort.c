/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:15:05 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/12 23:21:04 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_a(t_info *info)
{
	t_stack	*cur;

	if (info->b == NULL)
		return ;
	cur = info->b;
	while (cur)
	{
		pa(info, 0);
		ra(info, 0);
		cur = info->b;
	}
}

/*
	if radix value reamin only 2	-> 1 return
 	else							-> 0 return
*/
int	check_only2remain(t_stack *stack, int radix)
{
	t_stack	*cur;

	cur = stack;
	while (cur)
	{
		if (cur->data->base3[radix] != '2')
			return (0);
		cur = cur->next;
	}
	return (1);
}

/*
	[0]: pb
	[1]: pb rb
	[2]: ra
*/
void	atob(t_info *info, int radix, int print)
{
	t_stack	*cur;
	int		i;
	int		size;

	if (info == NULL)
		return ;
	cur = info->a;
	i = 0;
	size = get_stacksize(info->a);
	while (i < size)
	{
		printf("count:%d\n", i);
		if (cur->data->base3[radix] == '0')
			pb(info, print);
		if (cur->data->base3[radix] == '1')
		{
			pb(info, print);
			rb(info, print);
		}
		if (cur->data->base3[radix] == '2')
			ra(info, print);
		print_(info);
		cur = info->a;
		i++;
	}
	while (info->a)
		pb(info, print);
}

/*
	[0]: pa
	[1]: pa ra
	[2]: rb
*/
void	btoa(t_info *info, int radix, int print)
{
	t_stack	*cur;
	int		i;
	int		size;

	cur = info->b;
	size = get_stacksize(info->b);
	i = 0;
	while (i < size)
	{
		if (cur->data->base3[radix] == '0')
			pa(info, print);
		if (cur->data->base3[radix] == '1')
		{
			pa(info, print);
			ra(info, print);
		}
		if (cur->data->base3[radix] == '2')
			rb(info, print);
		cur = info->b;
		i++;
	}
	while (info->b)
		pa(info, print);
}

void	sort_3base(t_info *info, int print)
{
	int		radix;

	radix = info->max_len - 1;
	while (radix >= 0)
	{
		if (info->b == NULL)
			atob(info, radix, print);
		else
			btoa(info, radix, print);
		radix--;
	}
}
