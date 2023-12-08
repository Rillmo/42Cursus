/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:16:21 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/08 17:12:31 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	open_files(t_pipepack *pipepack)
{
	pipepack->ifd = open(pipepack->argv[1], O_RDONLY, 0644);
	dup2(pipepack->ifd, STDIN_FILENO);
	close(pipepack->ifd);
	pipepack->ofd = open(pipepack->argv[pipepack->argc - 1], \
	O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipepack->ofd < 0)
		err_bad_fd(pipepack->argv[pipepack->argc - 1]);
}

static void	child_process(t_pipepack *pipepack, int idx, t_cmd *cmd)
{
	if (idx == 2 && pipepack->ifd < 0)
		err_bad_fd(pipepack->argv[1]);
	close(pipepack->fds[0]);
	make_command(cmd, pipepack->argv[idx], pipepack);
	if (idx == pipepack->argc - 2)
		dup2(pipepack->ofd, STDOUT_FILENO);
	else
		dup2(pipepack->fds[1], STDOUT_FILENO);
	close(pipepack->fds[1]);
	if (execve(cmd->path, cmd->cmds, pipepack->envp) < 0)
		exit_with_err();
}

static void	parent_process(t_pipepack *pipepack)
{
	close(pipepack->fds[1]);
	dup2(pipepack->fds[0], STDIN_FILENO);
	close(pipepack->fds[0]);
}

void	connect_pipe(t_pipepack *pipepack)
{
	int		i;
	int		pid;
	t_cmd	cmd;
	pid_t	wpid;
	int		last_status;

	open_files(pipepack);
	i = 2;
	while (i < pipepack->argc - 1)
	{
		pipe(pipepack->fds);
		pid = fork();
		if (pid == 0)
			child_process(pipepack, i, &cmd);
		parent_process(pipepack);
		i++;
	}
	wpid = 1;
	while (wpid >= 0)
	{
		wpid = waitpid(-1, &pipepack->status, WNOHANG);
		if (wpid == pid)
			last_status = pipepack->status;
	}
	exit(WEXITSTATUS(last_status));
}
