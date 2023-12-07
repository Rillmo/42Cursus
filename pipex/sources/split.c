/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:20:12 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/07 20:38:19 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*backslash_deleter(char *str)
{
	int		i;
	int		j;
	int		flag;
	char	*result;

	i = -1;
	j = 0;
	result = (char *)ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	flag = 0;
	while (str[++i])
	{
		if (str[i] == '\\')
		{
			if (flag == 0)
				flag = 1;
			else
				flag = 0;
		}
		if (flag == 0)
			result[j++] = str[i];
		flag = 0;
	}
	return (result);
}

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static size_t	str_to_word(char *str, size_t org_len)
{
	size_t	idx;
	size_t	word_cnt;
	char	flag;

	idx = 0;
	word_cnt = 0;
	flag = 0;
	while (idx < org_len)
	{
		if (str[idx] == '\'' || str[idx] == '\"')
		{
			flag = str[idx];
			word_cnt++;
			str[idx++] = 0;
			while (idx < org_len && str[idx] != flag)
				idx++;
			str[idx++] = 0;
		}
		else if (!is_space(str[idx]))
		{
			word_cnt++;
			while (idx < org_len && !is_space(str[idx]))
				idx++;
		}
		else
		{
			str[idx] = 0;
			idx++;
		}
	}
	return (word_cnt);
}

static char	**clean(char **str_arr, char *str, size_t size)
{
	size_t	idx;

	idx = 0;
	while (idx < size)
	{
		free(str_arr[idx]);
		str_arr[idx] = NULL;
		idx++;
	}
	free(str_arr);
	free(str);
	str = NULL;
	return (NULL);
}

static char	**str_to_arr(char **result, char *str, size_t org_len)
{
	size_t	idx;
	size_t	word_idx;

	idx = 0;
	word_idx = 0;
	while (idx < org_len)
	{
		if (str[idx])
		{
			result[word_idx] = backslash_deleter(&str[idx]);
			if (!result[word_idx])
			{
				clean(result, str, word_idx);
				return (NULL);
			}
			word_idx++;
			while (str[idx] && idx < org_len)
				idx++;
		}
		else
			idx++;
	}
	free(str);
	return (result);
}

char	**new_split(char *s)
{
	size_t	words;
	size_t	len;
	char	*temp;
	char	**result;

	len = ft_strlen(s);
	temp = ft_strdup(s);
	if (!temp)
		return (NULL);
	words = str_to_word(temp, len);
	result = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!result)
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	return (str_to_arr(result, temp, len));
}
