/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:29:53 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/05 16:56:46 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	save_to_buff(int fd, char **buff, char **save)	// 초깃값 : fd, null, null
{
	int	read_size;
	int	i;

	i = 0;
	while ((*buff)[i])
		(*buff)[i++] = 0;
	read_size = read(fd, *buff, BUFFER_SIZE);
	if (read_size < 0)
		return (ERROR);
	if (read_size == 0)
		return (_EOF);
	*save = ft_strjoin(*save, *buff);
	if (strchr(*buff, '\n') == 0)	// IF \N NOT FOUND
		return (save_to_buff(fd, buff, save));
	return (1);
}

char	*get_right(char *save)
{
	char	*result;
	char	*pos;
	int		len;
	int		i;

	if (save == NULL)
		return (NULL);
	pos = strchr(save, '\n');
	if (pos == NULL)
		return (NULL);
	len = strlen(save) - (pos - save);
	result = (char *)calloc(len, sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (save[i])
	{
		result[i] = save[i + (pos - save + 1)];
		i++;
	}
	return (result);
}

char	*get_left(char **save, int flag)
{
	char	*result;
	char	*pos;
	int		len;
	int		i;

	if (*save == NULL)
		return (NULL);
	pos = strchr(*save, '\n');
	if (pos == NULL && flag != _EOF)
		return (NULL);
	if (pos == NULL && flag == _EOF)
		return (*save);
	len = pos - *save + 2;
	result = (char *)calloc(len, sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		result[i] = (*save)[i];
		i++;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buff;
	char		*result;
	int			flag;

	result = NULL;
	buff = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buff == NULL)
		return (NULL);
	save = (char *)calloc(0, 0);
	if (save == NULL)
	{
		free(buff);
		return (NULL);
	}
	flag = save_to_buff(fd, &buff, &save);
	result = get_left(&save, flag);
	save = get_right(save);
	free(buff);
	return (result);
}
int main()
{
	
	// int fd = open("test.txt", O_RDONLY);
	int fd = open("../../francinette/tests/get_next_line/fsoares/giant_line.txt", O_RDONLY);
	for (int i = 0; i<5; i++)
		printf("%s", get_next_line(fd));
	close(fd);

	return 0;
}