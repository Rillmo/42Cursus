/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:33:08 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/19 15:32:57 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
	int	i;
	int	j;
	int	*arr;
	int	key;

	arr = info->input;
	i = 1;
	while (i < info->size)
	{
		key = arr[i];
		j = i + 1;
		while (j <= info->size)
		{
			if (key == arr[j])
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	exit_with_err(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
