/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:22:33 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/10 19:25:59 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/errno.h>

typedef struct s_split
{
	char	*org;
	size_t	org_len;
	char	flag;
	size_t	word_count;
	char	**result;
	char	*temp;
}	t_split;

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
	int		ifd;
	int		ofd;
	int		tmp_fd;
}	t_pipepack;

// ==== process ====
void	connect_pipe(t_pipepack *pipepack);
// ==== parse ====
char	**new_split(char *s);
char	**parse_special(char *str);
// ==== heredoc ====
void	here_doc(t_pipepack *pipepack);
// ===== util =====
void	get_path_list(t_pipepack *pipepack);
void	set_pipepack(t_pipepack *pipepack, int argc, char **argv, char **envp);
void	make_command(t_cmd *cmd, char *cmd_name, t_pipepack *pipepack);
int		is_space(char c);
// ===== error =====
void	err_command_not_found(char *command);
void	err_bad_fd(char *filename);
void	exit_with_err(void);
void	check_err(void *content, void **tosave);

#endif