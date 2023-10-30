/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:28:41 by junkim2           #+#    #+#             */
/*   Updated: 2023/10/30 15:20:12 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_save(char *save)
{
	char	*result;
	int		i;
	int		start;

	i = 0;
	while (save[i] != 0 && save[i] != '\n')
		i++;
	if (save[i] == 0)
	{
		return (0);
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen(save) - i));
	if (result == 0)
		return (0);
	start = i + 1;
	i = 0;
	while (save[start] != 0 && save[start] != '\n')
		result[i++] = save[start++];
	result[i] = 0;
	free(save);
	return (result);
}

char	*until_new_line(char *save)
{
	char	*result;
	int		i;

	if (*save == 0)
		return (0);
	i = 0;
	while (save[i] != 0 && save[i] != '\n')
		i++;
	result = (char *)malloc(sizeof(char) * (i + 2));
	if (result == 0)
		return (0);
	i = 0;
	while (save[i] != 0)
	{
		result[i] = save[i];
		if (save[i] == '\n')
			break ;
		i++;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	static char	*save;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_size = 1;
	result = 0;
	while (!ft_strchr(save, '\n') && read_size != 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			return (0);
		buf[read_size] = 0;
		save = ft_strjoin(save, buf);
	}
	if (save == 0)
		return (0);
	result = until_new_line(save);
	save = new_save(save);
	return (result);
}
