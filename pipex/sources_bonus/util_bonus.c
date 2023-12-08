/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:31:38 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/08 18:09:33 by junkim2          ###   ########.fr       */
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
	if (pipepack->envp[i] == NULL)
		return ;
	path = ft_strchr(pipepack->envp[i], '=');
	path++;
	check_err(ft_split(path, ':'), (void *)&pipepack->path_list);
}

void	check_access(t_cmd *cmd, t_pipepack *pipepack)
{
	char	*tmp1;
	char	*tmp2;
	int		i;

	check_err(ft_strjoin("/", cmd->cmds[0]), (void *)&tmp1);
	i = 0;
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

void	make_command(t_cmd *cmd, char *cmd_name, t_pipepack *pipepack)
{
	cmd->cmds = new_split(cmd_name);
	check_err(cmd->cmds, NULL);
	cmd->path = ft_strdup(cmd->cmds[0]);
	if (ft_strchr(cmd->path, '/') != 0)
		return ;
	if (access(cmd->path, X_OK) < 0)
	{
		if (pipepack->path_list == NULL)
			err_command_not_found(cmd_name);
		check_access(cmd, pipepack);
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

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}
