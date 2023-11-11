/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:35:04 by macbookpro        #+#    #+#             */
/*   Updated: 2023/11/12 00:42:19 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*err_handler(t_list *lst)
{
	free(lst->buff);
	lst->buff = NULL;
	lst->current_size = 0;
	lst->total_size = 0;
	return (NULL);
}

void	ft_memmove(t_list *lst, int idx)
{
	int	i;

	i = 0;
	while (lst->buff[idx] != 0)
	{
		lst->buff[i] = lst->buff[idx];
		i++;
		idx++;
	}
	lst->current_size = i;
	while (lst->buff[i] != 0)
		lst->buff[i++] = 0;
}

char	*get_left(t_list *lst, int flag)
{
	char	*result;
	char	*pos;
	int		len;
	int		i;

	pos = ft_strchr(lst->buff, '\n');
	if (flag == _EOF && pos == NULL)
	{
		result = ft_strdup(lst->buff);
		if (result == NULL)
			return (_ERROR);
		return (result);
	}
	len = pos - lst->buff + 2;
	result = (char *)ft_calloc(len, sizeof(char));
	if (result == NULL)
		return (_ERROR);
	i = 0;
	while (i < len - 1)
	{
		result[i] = lst->buff[i];
		i++;
	}
	ft_memmove(lst, i);
	return (result);
}

int	read_line(int fd, t_list arr[])
{
	int	read_size;

	if (arr[fd].total_size - arr[fd].current_size < BUFFER_SIZE)
	{
		if (arr[fd].total_size == 0)
			arr[fd].total_size = BUFFER_SIZE;
		else
			arr[fd].total_size *= 2;
		arr[fd].buff = alloc_double(arr[fd].buff, arr[fd].total_size);
		if (arr[fd].buff == NULL)
			return (_ERROR);
	}
	read_size = 0;
	while (arr[fd].total_size - arr[fd].current_size > BUFFER_SIZE && \
ft_strchr(arr[fd].buff, '\n') == NULL)
	{
		read_size = read(fd, &(arr[fd].buff[arr[fd].current_size]), BUFFER_SIZE);
		if (read_size < 0)
			return (_ERROR);
		arr[fd].current_size += read_size;
		if (read_size == 0)
			return (_EOF);
	}
	if (ft_strchr(arr[fd].buff, '\n') == NULL)
		return (read_line(fd, arr));
	return (1);
}

// gnl
char	*get_next_line(int fd)
{
	static t_list	arr[10000];
	int				flag;
	char			*result;

	if (fd < 0)
		return (NULL);
	flag = read_line(fd, arr);
	if (flag == _ERROR)
		return (err_handler(&arr[fd]));
	if (flag == _EOF && arr[fd].buff[0] == 0)
		return (err_handler(&arr[fd]));
	result = get_left(&arr[fd], flag);
	if (result == _ERROR)
		return (err_handler(&arr[fd]));
	if (flag == _EOF)
	{
		free(arr[fd].buff);
		arr[fd].buff = NULL;
	}
	return (result);
}

// int main(void)
// {
// 	int fd = open("variable_nls.txt", O_RDONLY);
// 	char *str;

// 	str = "";
// 	while (str != NULL)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 	}
// 	// get_next_line(fd);
// 	// printf("%s\n", str);
// 	close(fd);
// }
