/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:35:21 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/06 11:04:23 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(int count, int size)
{
	char	*result;
	int		i;

	result = (char *)malloc(size * count);
	if (result == 0)
		return (0);
	i = 0;
	while (i < count * size)
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}

char	*ft_strchr(char *save, char c)
{
	int	i;

	i = 0;
	while (save[i])
	{
		if (save[i] == c)
			return (save + i);
		i++;
	}
	if (c == '\0')
		return (save + i);
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*result;
	int		str1_len;
	int		str2_len;
	int		i;
	int		j;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	result = ft_calloc(sizeof(char), str1_len * 2 + str2_len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < str1_len)
	{
		result[i] = str1[i];
		i++;
	}
	j = 0;
	while (j < str2_len && i < str1_len * 2 + str2_len)
	{
		result[i] = str2[j];
		i++;
		j++;
	}
	free(str1);
	return (result);
}

char	*ft_strdup(char *s1)
{
	char	*copy;
	int		origin_len;
	int		i;

	origin_len = ft_strlen(s1);
	copy = (char *)malloc((origin_len + 1) * sizeof(char));
	if (copy == 0)
		return (0);
	i = 0;
	while (s1[i] != 0)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}
