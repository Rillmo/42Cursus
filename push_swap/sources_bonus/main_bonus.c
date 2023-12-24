/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:21:56 by macbookpro        #+#    #+#             */
/*   Updated: 2023/12/22 15:27:28 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	free_all(t_info *info)
{
	t_stack	*cur;

	cur = info->a;
	while (cur)
	{
		free(cur);
		cur = cur->next;
	}
	cur = info->b;
	while (cur)
	{
		free(cur);
		cur = cur->next;
	}
	free(info->input);
}

int	is_sorted(t_info *info)
{
	t_stack	*cur;
	int		num;

	if (info->b != NULL)
		return (0);
	cur = info->a;
	while (cur)
	{
		num = cur->data;
		if (cur->next && num > cur->next->data)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 1)
		return (0);
	check_input_err(argc, argv);
	set_info(&info, argc, argv);
	check_dup_err(&info);
	set_action(&info);
	if (is_sorted(&info))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_all(&info);
	return (0);
}
