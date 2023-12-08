/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:20:12 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/08 19:02:13 by junkim2          ###   ########.fr       */
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

static void	count_word(t_split *split)
{
	size_t	idx;

	idx = 0;
	split->word_count = 0;
	while (idx < split->org_len)
	{
		if (split->temp[idx] == '\'' || split->temp[idx] == '\"')
		{
			split->flag = split->temp[idx];
			split->word_count++;
			split->temp[idx++] = 0;
			while (idx < split->org_len && split->temp[idx] != split->flag)
				idx++;
			split->temp[idx++] = 0;
		}
		else if (!is_space(split->temp[idx]))
		{
			split->word_count++;
			while (idx < split->org_len && !is_space(split->temp[idx]))
				idx++;
		}
		else
			split->temp[idx++] = 0;
	}
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

void	str_to_arr(t_split *split, char *str)
{
	size_t	idx;
	size_t	word_idx;

	idx = 0;
	word_idx = 0;
	while (idx < split->org_len)
	{
		if (str[idx])
		{
			split->result[word_idx] = backslash_deleter(&str[idx]);
			if (!split->result[word_idx])
			{
				clean(split->result, str, word_idx);
				return ;
			}
			word_idx++;
			while (str[idx] && idx < split->org_len)
				idx++;
		}
		else
			idx++;
	}
	free(str);
}

char	**new_split(char *s)
{
	t_split	split;

	split.org_len = ft_strlen(s);
	split.temp = ft_strdup(s);
	if (!split.temp)
		return (NULL);
	count_word(&split);
	split.result = (char **)ft_calloc(split.word_count + 1, sizeof(char *));
	if (!split.result)
	{
		free(split.temp);
		split.temp = NULL;
		return (NULL);
	}
	str_to_arr(&split, split.temp);
	return (split.result);
}
