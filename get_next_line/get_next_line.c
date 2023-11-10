/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:35:04 by macbookpro        #+#    #+#             */
/*   Updated: 2023/11/11 02:00:06 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_left(char *buff)
{
	char	*result;
	char	*pos;
	int		len;
	int		i;

	if (buff == NULL)
		return (_ERROR);
	pos = ft_strchr(buff, '\n');
	if (buff[0] != '\0' && pos == NULL)	// buff에 남은 값은 있는데 파일을 다읽음(EOF) : buff 복사해서 리턴
		return (ft_strdup(buff));
	if (buff[0] == '\0' && pos == NULL)	// buff에 남은 값도 없고 파일도 다읽음(EOF) : 그냥 함수 끝냄(NULL리턴)
		return (NULL);
	len = pos - buff + 2;
	result = (char *)ft_calloc(len, sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		result[i] = buff[i];
		i++;
	}
	return (result);
}

int	read_to_node(int fd, t_node arr[])
{
	int		read_size;
	char	*tmp;
	
// ---- error handling ----
	if (fd < 0 || read(fd, tmp, 0) < 0)
		return (_ERROR);
// ---- set arr ----
	if (arr[fd].count_buffering == 0)
		arr[fd].count_buffering = 1;
	if (arr[fd].buff == NULL)
		arr[fd].buff = (char *)ft_calloc(1, 1);
	tmp = (char *)ft_calloc(BUFFER_SIZE * arr[fd].count_buffering, sizeof(char));
// ---- recursive ----
	read_size = read(fd, tmp, BUFFER_SIZE);
	if (read_size < 0)
		return (_ERROR);
	tmp[read_size] = '\0';
	if (read_size == 0)
		return (_EOF);
	arr[fd].buff = ft_strjoin(arr[fd].buff, tmp);
	if (arr[fd].buff == NULL)
		return (_ERROR);
	free(tmp);
	if (ft_strchr(tmp, '\n') == NULL)
		return (read_to_node(fd, arr));
// ---- get left ----
	get_left(arr[fd].buff);
	return (1);
}

// gnl
char	*get_next_line(int fd)
{
	static t_node   arr[10240];
	t_node			*new;
	int				result;
	
	// new = find_or_make_node(fd, &arr);
	result = read_to_node(fd, arr);
	if (result == _ERROR)
	{
		free(arr[fd].buff);
		return (NULL);
	}
	if (result == _EOF)
		return (NULL);
	return (arr[fd].buff);
}
