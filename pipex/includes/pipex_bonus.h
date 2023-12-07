/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:22:33 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/07 16:25:24 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/errno.h>

typedef struct s_cmd
{
	char	*path;
	char	**cmds;
}	t_cmd;

typedef struct s_pipepack
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**path_list;
	int		status;
	int		fds[2];
	int		fd;
}	t_pipepack;

void	check_err(void *content, void **tosave);
void	exit_with_err(void);
void	connect_pipe(t_pipepack *pipepack);
void	make_command(t_cmd *cmd, char *cmd_name, t_pipepack *pipepack);
void	err_command_not_found(char *command);
void	err_bad_fd(char *filename);
char	**new_split(char *s);
char	**parse_special(char *str);
void	here_doc(t_pipepack *pipepack);

#endif