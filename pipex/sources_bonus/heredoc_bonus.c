/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:58:07 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/06 21:24:09 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	here_doc(t_pipepack *pipepack)
{
	char	*buff;
	int		tmp_fd;
	int		ofd;
	int		i;
	int		pid;
	t_cmd	cmd;
	int		wpid;
	int		mystatus;

	tmp_fd = open("tmpfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	buff = "";
	while (buff != NULL && ft_strnstr(buff, pipepack->argv[2], \
	sizeof(pipepack->argv[2])) == 0)
	{
		write(1, "pipe heredoc>", 13);
		buff = get_next_line(STDIN_FILENO);
		write(tmp_fd, buff, sizeof(buff));
	}
	dup2(tmp_fd, STDIN_FILENO);
	// close(tmp_fd);
	ofd = open(pipepack->argv[pipepack->argc - 1], \
	O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ofd < 0)
		err_bad_fd(pipepack->argv[pipepack->argc - 1]);
	i = 3;
	while (i < pipepack->argc - 1)
	{
		pipe(pipepack->fds);
		pid = fork();
		if (pid == 0)
		{
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
	// unlink("tmpfile");
	exit(WEXITSTATUS(mystatus));
}

// int main(int argc, char **argv)
// {
// 	here_doc(argv);
// 	return (0);
// }
