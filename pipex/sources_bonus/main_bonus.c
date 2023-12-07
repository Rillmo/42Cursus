/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:22:14 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/07 16:25:32 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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

	cmd->cmds = new_split(cmd_name);
	check_err(cmd->cmds, NULL);
	i = 0;
	cmd->path = ft_strdup(cmd->cmds[0]);
	if (ft_strchr(cmd->path, '/') != 0)
		return ;
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
		err_command_not_found(cmd_name);
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
	int			i;
	int			found;

	if (argc < 5)
		exit_with_err();
	i = 0;
	found = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			found = 1;
		i++;
	}
	if (found == 0)
		envp[0] = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:\
		/sbin:/usr/local/munki:/Library/Apple/usr/bin";
	set_pipepack(&pipepack, argc, argv, envp);
	get_path_list(&pipepack);
	if (ft_strnstr(argv[1], "here_doc", 8) != NULL)
	{
		here_doc(&pipepack);
		exit(EXIT_SUCCESS);
	}
	connect_pipe(&pipepack);
}
