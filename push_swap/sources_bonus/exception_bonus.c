/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:33:08 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/15 23:18:00 by junkim2          ###   ########.fr       */
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
	int	pivot;

	arr = info->input;
	i = 1;
	while (i <= info->size)
	{
		pivot = arr[i];
		j = i + 1;
		while (j <= info->size)
		{
			if (pivot == arr[j])
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_valid_action(char *str)
{
	int			i;
	const char	action_list1[8][3] = {"pa", "pb", "ra", "rb", \
	"rr", "sa", "sb", "ss"};
	const char	action_list2[3][4] = {"rra", "rrb", "rrr"};

	i = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[i]))
			exit_with_err();
		i++;
	}
	i = 0;
	while (i < 12)
	{
		if (!ft_strncmp(str, action_list1[i], 2) || \
		!ft_strncmp(str, action_list2[i], 3))
			exit_with_err();
		i++;
	}
}

void	exit_with_err(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
