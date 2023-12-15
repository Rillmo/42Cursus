/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:33:08 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/15 22:32:37 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_input_err(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	while (i < argc)
	{
		str = argv[i];
		j = 0;
		while (str[j])
		{
			if (!ft_isdigit(str[j]) && !is_sign(str[j]) \
				&& !is_space(str[j]))
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_dup_err(t_info *info)
{
	t_stack	*cur1;
	t_stack	*cur2;
	int		pivot;

	cur1 = info->a;
	while (cur1)
	{
		pivot = cur1->data->num;
		cur2 = cur1->next;
		while (cur2)
		{
			if (pivot == cur2->data->num)
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			cur2 = cur2->next;
		}
		cur1 = cur1->next;
	}
}

