/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:55:38 by macbookpro        #+#    #+#             */
/*   Updated: 2023/11/18 21:28:21 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	*ft_calloc(int count, int size)
{
	char	*result;
	int		i;

	result = (char *)malloc(size * count);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (NULL);
}

char	*alloc_double(t_list *lst)
{
	char	*result;
	int		buff_len;
	int		i;

	if (lst->total_size == 0)
		lst->total_size = BUFFER_SIZE;
	else
		lst->total_size *= 2;
	result = (char *)ft_calloc(lst->total_size + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	buff_len = ft_strlen(lst->buff);
	i = 0;
	while (i < buff_len)
	{
		result[i] = lst->buff[i];
		i++;
	}
	free(lst->buff);
	return (result);
}

char	*ft_strdup(char *s1)
{
	char	*copy;
	int		origin_len;
	int		i;

	origin_len = ft_strlen(s1);
	copy = (char *)ft_calloc(origin_len + 1, sizeof(char));
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
