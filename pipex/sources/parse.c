/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:26:04 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/06 22:36:15 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**parse_special(char *str)
{
	char	**result;
	char	*cpy;
	int		i;

	result = ft_calloc(3, sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		result[0][i] = str[i];
		i++;
	}
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
