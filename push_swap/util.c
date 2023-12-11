/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:42:44 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/11 20:09:33 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack **stack, int argc)
{
	t_stack	*min_ptr;
	t_stack	*cur;
	int		min;
	int		i;

	min = 0;
	i = 1;
	if (*stack == NULL)
		return ;
	while (i < argc)
	{
		cur = *stack;
		min = INT_MAX;
		while (cur)
		{
			if (min >= cur->data->num && cur->data->idx == -1)
			{
				min_ptr = cur;
				min = cur->data->num;
			}
			cur = cur->next;
		}
		min_ptr->data->idx = i;
		i++;
	}
}

void	conv_3base(t_stack *stack)
{
	int		max_len;
	int		i;
	char	*result;
	int		n;
	t_stack	*cur;

	max_len = get_max_len(stack);
	cur = stack;
	while (cur)
	{
		result = (char *)ft_calloc(max_len + 1, sizeof(char));
		if (result == NULL)
			return ;
		n = cur->data->idx;
		i = max_len - 1;
		while (i >= 0)
		{
			result[i] = n % 3 + '0';
			n /= 3;
			i--;
		}
		cur->data->base3 = result;
		cur = cur->next;
	}
}

int	get_3base_len(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 3;
		len++;
	}
	return (len);
}

t_data	*parse_data(char *str)
{
	t_data	*result;

	result = (t_data *)ft_calloc(1, sizeof(t_data));
	result->str = str;
	result->num = ft_atoi(str);
	result->idx = -1;
	return (result);
}
