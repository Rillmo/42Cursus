/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:16:21 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/06 18:37:45 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	connect_pipe(t_pipepack *pipepack)
{
	int		ifd;
	int		ofd;
	int		i;
	int		pid;
	t_cmd	cmd;
	pid_t 	wpid;
	int		mystatus;

	ifd = open(pipepack->argv[1], O_RDONLY, 0644);
	dup2(ifd, STDIN_FILENO);
	close(ifd);
	ofd = open(pipepack->argv[pipepack->argc - 1], \
	O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ofd < 0)
		err_bad_fd(pipepack->argv[pipepack->argc - 1]);
	i = 2;
	while (i < pipepack->argc - 1)
	{
		pipe(pipepack->fds);
		pid = fork();
		if (pid == 0)
		{
			if (i == 2 && ifd < 0)
				err_bad_fd(pipepack->argv[1]);
			close(pipepack->fds[0]);
			make_command(&cmd, pipepack->argv[i], pipepack);
			if (i == pipepack->argc - 2)
				dup2(ofd, STDOUT_FILENO);
			else
				dup2(pipepack->fds[1], STDOUT_FILENO);
			close(pipepack->fds[1]);
			if (execve(cmd.path, cmd.cmds, pipepack->envp) < 0)
				exit_with_err();
		}
		close(pipepack->fds[1]);
		dup2(pipepack->fds[0], STDIN_FILENO);
		close(pipepack->fds[0]);
		i++;
	}
	wpid = 1;
	while (wpid >= 0)
	{
		wpid = waitpid(-1, &pipepack->status, WNOHANG);
		if (wpid == pid)
			mystatus = pipepack->status;
	}
	exit(WEXITSTATUS(mystatus));
}
