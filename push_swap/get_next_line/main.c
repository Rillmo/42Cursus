#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *str;

    str = "";
    while (str != NULL)
    {
        str = get_next_line(fd);
	    printf("%s", str);
    }
    close(fd);
}