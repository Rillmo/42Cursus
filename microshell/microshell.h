#ifndef MICROSHELL_H
#define MICROSHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

typedef struct s_info
{
	int argc;
	char **argv;
	char **envp;
	int	fds[2];
}	t_info;


void	connect_pipe(t_info *info);

#endif