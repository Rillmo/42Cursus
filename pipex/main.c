/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:22:14 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/01 12:15:26 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_command(t_cmd *cmd, char *cmd_name, char **path_list)
{
	char	*tmp1;
	char	*tmp2;
	
	cmd->cmds = ft_split(cmd_name, ' ');
	if (access(cmd->cmds[0], X_OK) == 0)
		cmd->path = ft_strdup(cmd->cmds[0]);
	else
	{
		tmp1 = ft_strjoin("/", cmd->cmds[0]);
		for (int i=0; path_list[i]!=0; i++)
		{
			tmp2 = ft_strjoin(path_list[i], tmp1);
			if (access(tmp2, X_OK) == 0)
			{
				cmd->path = tmp2;
				break;
			}
		}
	}
	// error
}

int	main(int argc, char **argv, char **envp)
{
	char	*file1;
	t_cmd	cmd1;
	char	*file2;
	int		i;
	char	*path;
	char	**path_list;
	int		fd[2];
	int		fd1, fd2;
	pid_t	pid1;
	int		status;

	file1 = argv[1];
	file2 = argv[3];

	// printf("%d\n", access("/./pipex", X_OK));
	(void)argc;
	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			break ;
		i++;
	}
	if (envp[i] == 0)
	{
		printf("error!\n");
		exit(EXIT_FAILURE);
	}
	path = ft_strchr(envp[i], '=');
	path++;
	path_list = ft_split(path, ':');
	
	make_command(&cmd1, argv[2], path_list);
//==========================================================

	// fd1 = open(file1, O_RDONLY);
	// fd_tmp = open("tmpfile", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	pipe(fd);

	pid1 = fork();	// parent | child(pid=0)
	if (pid1 == 0)	// child
	{
		fd2 = open(file2, O_WRONLY);
		dup2(fd2, STDOUT_FILENO);
		close(fd[0]);	// close gate that can write to pipe (read-end pipe)
		dup2(fd[1], STDIN_FILENO);	// turn write-end pipe to stdin
		execve(cmd1.path, cmd1.cmds, envp);
	}
	else			// parent
	{
		fd1 = open(file1, O_RDONLY);
		dup2(fd1, STDIN_FILENO);
		close(fd[1]);	// close gate that can read from pipe (write-end pipe)
		dup2(fd[0], STDOUT_FILENO);	// turn read-end pipe to stdout
		execve(cmd1.path, cmd1.cmds, envp);
		waitpid(pid1, &status, 0);	// wait for child
	}
//==========================================================
	/*fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd_tmp, STDIN_FILENO);
		dup2(fd2, STDOUT_FILENO);
		execve(cmd1.path, cmd1.cmds, envp);
	}
	else
		waitpid(pid2, &status, 0);*/
}
