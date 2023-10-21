
#include "get_next_line.h"
#define BUF_SIZE 32

char	*get_next_line(int fd)
{
	size_t	i;
	char	buf[BUF_SIZE];

	i = 0;
	read(fd, buf, BUF_SIZE);
	write(fd, &buf, BUF_SIZE);
	close(fd);
	return (0);
}
