/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:21:56 by macbookpro        #+#    #+#             */
/*   Updated: 2023/12/16 15:07:14 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	print_(t_info *info)
{
	int	i;
	t_stack	*cur;

	i = 1;
	ft_printf(" input\t| ");
	while (i <= info->size)
		ft_printf("%d ", info->input[i++]);
	ft_printf("\n");
	cur = info->a;
	ft_printf(" A\t| ");
	while (cur)
	{
		ft_printf("%d ", cur->data);
		cur = cur->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_info	info;

	check_input_err(argc, argv);
	set_info(&info, argc, argv);
	check_dup_err(&info);
	print_(&info);
	set_action(&info);
	return (0);
}
