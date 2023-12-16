/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:37:50 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/16 15:10:37 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	set_stack(t_info *info)
{
	int	i;
	
	info->a = 0;
	info->b = 0;
	i = info->size;
	while (i >= 1)
		stack_addfront(&(info->a), info->input[i--]);
}

void	set_info(t_info *info, int argc, char **argv)
{
	int		i;
	int		count;

	info->argc = argc;
	info->argv = argv;
	i = 1;
	count = 0;
	while (i < argc)
		count += count_digit(argv[i++]);
	info->size = count;
	info->input = parse_argv(info);
	set_stack(info);
}

void	do_action(t_info *info, char *action)
{
	if (ft_strncmp(action, "sa", 2))
		sa(info, 1);
	else if (ft_strncmp(action, "sb", 2))
		sb(info, 1);
	else if (ft_strncmp(action, "pa", 2))
		pa(info, 1);
	else if (ft_strncmp(action, "pb", 2))
		pb(info, 1);
	else
		ft_printf("그딴거 없음\n");
}

void	set_action(t_info *info)
{
	char	*buff;

	buff = "";
	while (buff)
	{
		buff = get_next_line(STDIN_FILENO);
		// check_valid_action(buff);
		do_action(info, buff);
		// do-action
	}
}
