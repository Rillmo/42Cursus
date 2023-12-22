/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:30:13 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/22 15:24:52 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all(t_info *info)
{
	t_stack	*cur;
	t_stack	*next;
	int		i;

	cur = info->a;
	while (cur)
	{
		next = cur->next;
		free(cur->data->base3);
		free(cur->data);
		free(cur);
		cur = next;
	}
	i = 1;
	while (i <= info->size)
	{
		free(info->sorted[i]->base3);
		free(info->sorted[i]);
		i++;
	}
	free(info->sorted);
	free(info->origin);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc <= 1)
		return (0);
	check_input_err(argc, argv);
	set_origin(&info, argc, argv);
	check_dup_err(&info);
	if (is_sorted(&info))
		exit(0);
	if (info.size <= 5)
		man_sorting(&info);
	sort_3base(&info, 0);
	move_to_a(&info, 0);
	save_to_sorted(&info);
	sort_3base(&info, 1);
	move_to_a(&info, 1);
	free_all(&info);
	return (0);
}
