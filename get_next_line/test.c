#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int	fd;
	char	buf[BUFFER_SIZE];
	char	*str;
	
	if (argv[1] == 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("file open error!");
		close(fd);
		return (0);
	}
	memset(buf, 0, BUFFER_SIZE);
	str = 0;
	if (read(fd, buf, BUFFER_SIZE - 1) > 0)
	{
		if (str == 0)
			str = strdup(buf);
		else
			strcat(str, buf);
		memset(buf, 0, BUFFER_SIZE);
	}
	printf("%s", str);
	close(fd);
	return (0);
}
