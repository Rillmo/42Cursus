/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:26:04 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/06 22:47:24 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	**parse_special(char *str)
{
	char	**result;
	char	*cpy;
	int		i;

	result = ft_calloc(3, sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	if (ft_strnstr(str, "awk", 3) != 0)
		result[0] = "awk";
	else if (ft_strnstr(str, "sed", 3) != 0)
		result[0] = "sed";
	cpy = ft_strdup(str + 4);
	i = 3;
	while (str[i] != 0)
	{
		if (str[i] == '\'')
		{
			result[1] = ft_strtrim(cpy, "\'");
			return (result);
		}
		if (str[i] == '\"')
		{
			result[1] = ft_strtrim(cpy, "\"");
			return (result);
		}
		i++;
	}
	return (result);
}
