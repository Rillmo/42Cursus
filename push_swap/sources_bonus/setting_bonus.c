/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:37:50 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/15 23:21:10 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
}

void	do_action(t_info *info, char *action)
{
	if (ft_strncmp(action, "pa"))
}

void	set_action(t_info *info)
{
	char	*buff;

	(void)info;
	buff = "";
	while (buff)
	{
		buff = get_next_line(STDIN_FILENO);
		check_valid_action(buff);

	}
}
