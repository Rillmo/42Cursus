/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:29:53 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/05 22:25:07 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	save_to_buff(int fd, char **buff, char **save)
{
	int	read_size;
	int	i;

	i = 0;
	(*buff)[0] = '\0';
	read_size = read(fd, *buff, BUFFER_SIZE);
	if (read_size < 0)
		return (_ERROR);
	(*buff)[read_size] = '\0';
	if (read_size == 0)
		return (_EOF);
	*save = ft_strjoin(*save, *buff);
	if (*save == NULL)
		return (_ERROR);
	if (ft_strchr(*buff, '\n') == 0)
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
	pos = ft_strchr(save, '\n');
	if (pos == NULL)
	{
		free(save);
		return (NULL);
	}
	len = ft_strlen(save) - (pos - save);
	result = (char *)ft_calloc(len, sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (save[i + (pos - save + 1)])
	{
		result[i] = save[i + (pos - save + 1)];
		i++;
	}
	free(save);
	return (result);
}

char	*get_left(char *save, int flag)
{
	char	*result;
	char	*pos;
	int		len;
	int		i;

	if (save == NULL || flag == _ERROR)
		return (NULL);
	pos = ft_strchr(save, '\n');
	if (pos == NULL && flag != _EOF)	// ERR!
		return (NULL);
	if (save[0] != '\0' && pos == NULL && flag == _EOF)	// save에 남은 값은 있는데 파일을 다읽음(EOF)
		return (ft_strdup(save));
	if (save[0] == '\0' && pos == NULL && flag == _EOF)	// save에 남은 값도 없고 파일도 다읽음(EOF)
		return (NULL);
	len = pos - save + 2;
	result = (char *)ft_calloc(len, sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		result[i] = save[i];
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

	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buff == NULL)
		return (NULL);
	if (save == NULL)
		save = (char *)ft_calloc(1, 1);
	if (save == NULL)
	{
		free(buff);
		return (NULL);
	}
	flag = save_to_buff(fd, &buff, &save);
	result = get_left(save, flag);
	save = get_right(save);
	if (flag == _ERROR)
	{
		free(save);
		save = NULL;
	}
	free(buff);
	return (result);
}

/*int main()
{
	char	*res;
	// int fd1 = open("test.txt", O_RDONLY);
	int fd2 = open("../../francinette/tests/get_next_line/fsoares/read_error.txt", O_RDONLY);
	// fd1 = open("test.txt", O_RDONLY);
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd2));
	// res = "";
	// while (res != 0)
	// {
	// 	res = get_next_line(fd1);
	// 	if (res != 0)
	// 		printf("%s", res);
	// }
	res = strdup("");
	for (int i =0; i<2; i++)
		printf("%s", get_next_line(fd2));
	do 
	{
		res = get_next_line(fd2);
		free(res);
	} while (res != NULL);
	printf("%s", get_next_line(fd2));
	free(res);
	close(fd2);
	// close(fd1);
	return 0;
}*/