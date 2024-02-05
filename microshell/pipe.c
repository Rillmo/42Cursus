#include "microshell.h"

void	connect_pipe(t_info *info, int idx) {
	int	pid;

	
	pipe(info->fds);
	pid = fork();
	if (pid == 0)

}