/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:37:50 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/19 16:54:01 by junkim2          ###   ########.fr       */
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
	int	i;
	int	count;

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

void	do_action2(t_info *info, char *action)
{
	if (ft_strncmp(action, "ra", 2) == 0 && ft_strlen(action) == 3)
		ra(info, 0);
	else if (ft_strncmp(action, "rb", 2) == 0 && ft_strlen(action) == 3)
		rb(info, 0);
	else if (ft_strncmp(action, "rra", 3) == 0 && ft_strlen(action) == 4)
		rra(info, 0);
	else if (ft_strncmp(action, "rrb", 3) == 0 && ft_strlen(action) == 4)
		rrb(info, 0);
	else if (ft_strncmp(action, "rrr", 3) == 0 && ft_strlen(action) == 4)
	{
		rra(info, 0);
		rrb(info, 0);
	}
	else if (ft_strncmp(action, "rr", 2) == 0 && ft_strlen(action) == 3)
	{
		ra(info, 0);
		rb(info, 0);
	}
	else
		exit_with_err();
}

void	do_action1(t_info *info, char *action)
{
	if (ft_strncmp(action, "sa", 2) == 0 && ft_strlen(action) == 3)
		sa(info, 0);
	else if (ft_strncmp(action, "sb", 2) == 0 && ft_strlen(action) == 3)
		sb(info, 0);
	else if (ft_strncmp(action, "ss", 2) == 0 && ft_strlen(action) == 3)
	{
		sa(info, 0);
		sb(info, 0);
	}
	else if (ft_strncmp(action, "pa", 2) == 0 && ft_strlen(action) == 3)
		pa(info, 0);
	else if (ft_strncmp(action, "pb", 2) == 0 && ft_strlen(action) == 3)
		pb(info, 0);
	else
		do_action2(info, action);
}

void	set_action(t_info *info)
{
	char	*buff;

	buff = "";
	while (buff)
	{
		buff = get_next_line(STDIN_FILENO);
		if (buff == NULL)
			return ;
		do_action1(info, buff);
		free(buff);
	}
}
