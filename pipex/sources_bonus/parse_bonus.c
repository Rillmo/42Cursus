/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:26:04 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/08 18:22:41 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	parse_quote(char ***result, char *str)
{
	int		i;
	char	*cpy;

	i = 3;
	cpy = ft_strdup(str + 4);
	while (str[i] != 0)
	{
		if (str[i] == '\'')
		{
			*result[1] = ft_strtrim(cpy, " \'");
			return ;
		}
		if (str[i] == '\"')
		{
			*result[1] = ft_strtrim(cpy, " \"");
			return ;
		}
		i++;
	}
}

char	**parse_special(char *str)
{
	char	**result;

	result = (char **)ft_calloc(3, sizeof(char *));
	if (result == NULL)
		return (NULL);
	if (ft_strnstr(str, "awk", 3) != 0)
		result[0] = "awk";
	else if (ft_strnstr(str, "sed", 3) != 0)
		result[0] = "sed";
	parse_quote(&result, str);
	return (result);
}
