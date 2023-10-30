/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:49:27 by junkim2           #+#    #+#             */
/*   Updated: 2023/10/30 15:19:36 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	d_len;
	size_t	s_len;

	idx = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	dst += d_len;
	idx = d_len;
	if (dstsize < d_len)
		return (s_len + dstsize);
	while (idx + d_len + 1 < dstsize && src[idx])
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = 0;
	return (d_len + s_len);
}

// char	*ft_strjoin(char *s1, char const *s2)
// {
// 	int		i;
// 	char	*result;

// 	if (s1 == 0)
// 	{
// 		s1 = (char *)malloc(1 * sizeof(char));
// 		s1[0] = 0;
// 	}
// 	if (s1 == 0 || s2 == 0)
// 		return (0);
// 	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (result == 0)
// 		return (0);
// 	i = -1;
// 	if (s1 != 0)
// 		while (s1[++i] != 0)
// 			result[i] = s1[i];
// 	while (*s2 != 0)
// 		result[i++] = *s2++;
// 	result[ft_strlen(s1) + ft_strlen(s2) + 1] = 0;
// 	free(s1);
// 	return (result);
// }

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*ft_strdup(const char *s1)
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

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	if (s == 0)
		return (0);
	tmp = (char *)s;
	while (*tmp != 0)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp++;
	}
	if ((char)c == '\0')
		return (tmp);
	return (0);
}
