#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *res;
    res = get_next_line(fd);
    while (res > 0)
    {
        printf("%s", res);
        res = get_next_line(fd);
    }
    return (0);
}