/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:29:53 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/04 22:56:50 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	save_to_buff(int fd, char **save)	// 초깃값 : fd, null
{
	int			read_size;
	char		*buff;

	buff = (char *)calloc(BUFFER_SIZE, sizeof(char));
	if (buff == 0)
		return (ERROR);
	read_size = read(fd, buff, BUFFER_SIZE);
	if (read_size < 0)
		return (ERROR);
	if (read_size == 0)
		return (_EOF);
	if (strchr(buff, '\n') != 0)	// SAVE TO BUFF!
	{
		*save = ft_strjoin(*save, buff);
		return (1);
	}
	save_to_buff(fd, save);
}

char	*get_next_line(int fd)
{
	static char	*save;

	
	save_to_buff(fd, &save);
	// if (s == 0 || (s == 2 && ft_strlen(save) == 0))
	// {
	// 	free(save);
	// 	save = NULL;
	// 	return (0);
	// }
	// if (s == 2 && ft_strchr(save, '\n') == -1)
	// {
	// 	result = ft_strjoin("\0", save);
	// 	free(save);
	// 	save = NULL;
	// 	return (result);
	// }
	// result = split_newline(&save);
	// if (result == NULL)
	// {
	// 	free(save);
	// 	save = NULL;
	// 	return (NULL);
	// }
	// ltrim(&save, ft_strlen(result));
	// return (result);
	printf("%s", save);
}

char	*split_newline(char **save)
{
	char	*res;
	int		idx;
	int		i;

	idx = ft_strchr(*save, '\n');
	res = (char *)ft_calloc(idx + 2, sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i <= idx)
	{
		res[i] = (*save)[i];
		i++;
	}
	return (res);
}

void	ltrim(char **save, int len)
{
	char	*result;
	int		size;
	int		i;

	size = ft_strlen(*save) - len;
	result = (char *)ft_calloc(sizeof(char), size + 1);
	if (result == NULL)
	{
		free(*save);
		*save = NULL;
		return ;
	}
	i = 0;
	while (i < size)
	{
		result[i] = (*save)[i + len];
		i++;
	}
	free(*save);
	*save = result;
}


int main()
{
	// char *d;

	// d = calloc(10, 1);
	
	int fd = open("test.txt", O_RDONLY);
	// int fd = open("../../francinette/tests/get_next_line/fsoares/giant_line.txt", O_RDONLY);
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("\n=======\n");

	// close(fd);
	get_next_line(fd);

	return 0;
}