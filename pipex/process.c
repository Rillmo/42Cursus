/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:16:21 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/01 22:17:46 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(t_pipepack *pipepack, pid_t pid1, pid_t pid2)
{
	// if (waitpid(pid1, &pipepack->status, 0) < 0)
	// 	exit_with_err();
	// if (waitpid(pid2, &pipepack->status, 0) < 0)
	// 	exit_with_err();
	(void)pid1;
	(void)pid2;
	wait(&pipepack->status);
	wait(&pipepack->status);
}

void	child_process2(t_pipepack *pipepack, t_cmd cmd2)
{
	int	fd;

	fd = open(pipepack->argv[4], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (fd < 0)
		exit_with_err();
	if (cmd2.path == NULL)
		exit_with_err();
	if (dup2(fd, STDOUT_FILENO) < 0)
		exit_with_err();
	if (close(pipepack->fds[1]) < 0)
		exit_with_err();
	if (dup2(pipepack->fds[0], STDIN_FILENO) < 0)
		exit_with_err();
	if (execve(cmd2.path, cmd2.cmds, pipepack->envp) < 0)
		exit_with_err();
}

void	connect_pipe(t_pipepack *pipepack)
{
	int		ifd;
	int		ofd;
	int		i;
	int		pid;
	t_cmd	cmd;

	ifd = open(pipepack->argv[1], O_RDONLY);
	dup2(ifd, STDIN_FILENO);
	i = 2;
	while (i < pipepack->argc - 2)
	{
		pipe(pipepack->fds);
		pid = fork();
		if (pid == 0)
		{
			make_command(&cmd, pipepack->argv[i], pipepack);
			// printf("%s\n", cmd.path);
			close(pipepack->fds[0]);
			dup2(pipepack->fds[1], STDOUT_FILENO);
			close(pipepack->fds[1]);
			if (execve(cmd.path, cmd.cmds, pipepack->envp) < 0)
				exit_with_err();
		}
		dup2(pipepack->fds[0], STDIN_FILENO);
		close(pipepack->fds[0]);
		close(pipepack->fds[1]);
		i++;
	}
	ofd = open(pipepack->argv[pipepack->argc - 1], \
	O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (ofd < 0)
		exit_with_err();
	pid = fork();
	if (pid == 0)
	{
		make_command(&cmd, pipepack->argv[pipepack->argc - 2], pipepack);
		dup2(ofd, STDOUT_FILENO);
		execve(cmd.path, cmd.cmds, pipepack->envp);
	}
}
