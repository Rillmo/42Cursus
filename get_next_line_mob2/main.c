#include "get_next_line.h"
#include <stdlib.h>

int main(void)
{
    char *save = (char *)calloc(1, sizeof(char));
    save[0] = 'a';
    char *buff = (char *)calloc(3, sizeof(char));
    buff[0] = 'b';
    buff[1] = 'c';
    buff[2] = 'd';


    save = ft_strjoin(save, buff);
    printf("%s\n", save);
    save = ft_strjoin(save, buff);
    printf("%s\n", save);
}