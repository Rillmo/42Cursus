/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:22:14 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/05 22:14:45 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_path_list(t_pipepack *pipepack)
{
	int		i;
	char	*path;

	i = 0;
	while (pipepack->envp[i] != 0)
	{
		if (ft_strncmp("PATH", pipepack->envp[i], 4) == 0)
			break ;
		i++;
	}
	check_err(pipepack->envp[i], NULL);
	path = ft_strchr(pipepack->envp[i], '=');
	path++;
	check_err(ft_split(path, ':'), (void *)&pipepack->path_list);
}

void	make_command(t_cmd *cmd, char *cmd_name, t_pipepack *pipepack)
{
	char	*tmp1;
	char	*tmp2;
	int		i;

	cmd->cmds = ft_split(cmd_name, ' ');
	check_err(cmd->cmds, NULL);
	i = 0;
	cmd->path = ft_strdup(cmd->cmds[0]);
	if (access(cmd->path, X_OK) < 0)
	{
		check_err(ft_strjoin("/", cmd->cmds[0]), (void *)&tmp1);
		while (pipepack->path_list[i] != 0)
		{
			check_err(ft_strjoin(pipepack->path_list[i], tmp1), (void *)&tmp2);
			if (access(tmp2, X_OK) == 0)
			{
				cmd->path = tmp2;
				break ;
			}
			i++;
		}
	}
	if (access(cmd->path, X_OK) < 0)
		err_command_not_found();
}

void	set_pipepack(t_pipepack *pipepack, int argc, char **argv, char **envp)
{
	pipepack->argv = argv;
	pipepack->argc = argc;
	pipepack->envp = envp;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipepack	pipepack;

	if (argc < 5)
		exit_with_err();
	set_pipepack(&pipepack, argc, argv, envp);
	get_path_list(&pipepack);
	connect_pipe(&pipepack);
}
