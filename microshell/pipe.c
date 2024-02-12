#include "microshell.h"

t_cmd	*make_cmd(t_info *info, int start, int end)
{
	t_cmd	*cmd;
	int		count;
	int		j;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (cmd == 0)
		fatal_error();
	count = end - start;
	cmd->arg = (char **)malloc(sizeof(char *) * (count + 1));
	if (cmd->arg == 0)
		fatal_error();
	j = 0;
	for (int i=start; i<end; i++) {
		cmd->arg[j++] = info->argv[i];
	}
	cmd->arg[j] = 0;
	cmd->cmd_name = info->argv[start];
	return cmd;
}

void	child_process(t_info *info, int start, int end, int last) {
	t_cmd *cmd;

	if (close(info->fds[0]) < 0)
		fatal_error();
	if (!last) {
		if (dup2(info->fds[1], 1) < 0)
			fatal_error();
	}
	if (close(info->fds[1]) < 0)
		fatal_error();
	cmd = make_cmd(info, start, end);
	if (execve(cmd->cmd_name, cmd->arg, info->envp) < 0)
		exec_error(cmd->cmd_name);
}

void	parent_process(t_info *info) {	
	if (close(info->fds[1]) < 0 || dup2(info->fds[0], 0) < 0 || \
		close(info->fds[0]) < 0)
		fatal_error();
}

void	connect_pipe(t_info *info, int start, int end, int last)
{
	int	pid;

	if (pipe(info->fds) < 0)
		fatal_error();
	info->pid = fork();
	if (info->pid < 0)
		fatal_error();
	if (info->pid == 0) {
		child_process(info, start, end, last);
	}
	parent_process(info);
}
