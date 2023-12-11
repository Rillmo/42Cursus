/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:58:07 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/10 19:00:33 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	open_files(t_pipepack *pipepack)
{
	char	*buff;

	pipepack->tmp_fd = open(".tmpfile", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	buff = ft_calloc(1, 1);
	while (buff != NULL)
	{
		free(buff);
		write(1, "pipe heredoc> ", 14);
		buff = get_next_line(STDIN_FILENO);
		if (ft_strnstr(buff, pipepack->argv[2], ft_strlen(pipepack->argv[2])))
			break ;
		write(pipepack->tmp_fd, buff, ft_strlen(buff));
	}
	free(buff);
	close(pipepack->tmp_fd);
	pipepack->tmp_fd = open(".tmpfile", O_RDONLY, 0644);
	dup2(pipepack->tmp_fd, STDIN_FILENO);
	close(pipepack->tmp_fd);
	pipepack->ofd = open(pipepack->argv[pipepack->argc - 1], \
	O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (pipepack->ofd < 0)
		err_bad_fd(pipepack->argv[pipepack->argc - 1]);
}

static void	child_process(t_pipepack *pipepack, int idx, t_cmd *cmd)
{
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

void	waiting_process(t_pipepack *pipepack, int pid, int *last_status)
{
	int	wpid;

	wpid = 1;
	while (wpid >= 0)
	{
		wpid = waitpid(-1, &pipepack->status, WNOHANG);
		if (wpid == pid)
			*last_status = pipepack->status;
	}
	unlink(".tmpfile");
}

void	here_doc(t_pipepack *pipepack)
{
	int		i;
	int		pid;
	t_cmd	cmd;
	int		last_status;

	open_files(pipepack);
	i = 3;
	while (i < pipepack->argc - 1)
	{
		pipe(pipepack->fds);
		pid = fork();
		if (pid == 0)
			child_process(pipepack, i, &cmd);
		parent_process(pipepack);
		i++;
	}
	close(pipepack->ofd);
	waiting_process(pipepack, pid, &last_status);
	exit(WEXITSTATUS(last_status));
}
