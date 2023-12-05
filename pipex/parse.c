/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:26:04 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/05 22:45:01 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_awk(char *str)
{
	char	**result;
	char	*cpy;
	int		i;

	result = ft_calloc(3, sizeof(char *));
	if (result == 0)
		return (NULL);
	result[0] = "awk";
	cpy = ft_strdup(str + 4);
	printf("%s\n", str);
	i = 4;
	ft_strtrim(cpy, "\'");
	printf("%s\n", cpy);
	// while (str[i] != 0 && str[i] != '\'' && str[i] != '\"')
	// 	i++;
	// start = i + 1;
	// while (str[i] != 0 && str[i] != '\'' && str[i] != '\"')
	// 	i++;
	// end = i;
	// printf("%d %d\n", start, end);
	// result[1] = ft_calloc(end - start + 1, sizeof(char));
	// if (result[1] == NULL)
	// 	return (NULL);
	// i = start;
	// while (str[i] != 0 && i < end)
	// 	*result[1]++ = str[i];
	// *result[1] = 0;
	return (result);
}
int main(void)
{
	char *str = "awk \'{count++} END {print count}\'";
	char	**result;
	result = parse_awk(str);
	printf("%s\n", result[0]);
	printf("%s\n", result[1]);
}
