#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	find_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			return (i);
		}
		i++;
	}
	return (-1);
}

char *get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	int		read_size;
	int		idx;

	tmp = 0;
	read_size = read(fd, buf, BUFFER_SIZE);
	buf[read_size] = '\0';
	idx = 0;
	while (read_size > 0)		// read to buffer
	{
		if (tmp == 0)
			tmp = strdup(buf);
		else
			strcat(tmp, buf);					// now tmp has string
		memset(buf, 0, BUFFER_SIZE + 1);		// flush buffer
		idx = find_newline(tmp);
		if (idx != -1)
		{
			lseek(fd, (sizeof(tmp) - idx + 1) * -1, SEEK_CUR);
			return (strdup(tmp));
		}
		read_size = read(fd, buf, BUFFER_SIZE);	// read again to buffer
		buf[read_size] = '\0';
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*tmp;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		printf("file opening error");
		return (0);
	}
	tmp = get_next_line(fd);
	while (tmp != 0)
	{
		printf("%s", tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (0);
}
