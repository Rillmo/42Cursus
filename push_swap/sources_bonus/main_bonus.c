/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:21:56 by macbookpro        #+#    #+#             */
/*   Updated: 2023/12/15 23:09:39 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	print_(t_info *info)
{
	int	i;

	i = 1;
	ft_printf(" input\t| ");
	while (i <= info->size)
		ft_printf("%d ", info->input[i++]);
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
