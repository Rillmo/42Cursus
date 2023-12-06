/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:47:38 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/06 18:52:18 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	exit_with_err(void)
{
	perror(strerror(errno));
	exit(EXIT_FAILURE);
}

void	err_bad_fd(char *filename)
{
	int	i;

	i = 0;
	write(2, "pipex: ", 7);
	while (filename[i] != 0)
		write(2, &filename[i++], 1);
	write(2, ": ", 2);
	write(2, "No such file or directory\n", 26);
	exit(EXIT_FAILURE);
}

void	err_command_not_found(char *command)
{
	int	i;

	i = 0;
	write(2, "pipex: ", 7);
	while (command[i] != 0)
		write(2, &command[i++], 1);
	write(2, ": ", 2);
	write(2, "command not found\n", 18);
	exit(127);
}

/*	if content is null (error occurs) : call exit_program
	if content is not null (no error) : save to tosave */
void	check_err(void *content, void **tosave)
{
	if (content == 0)
	{
		perror(strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (tosave != NULL)
		*tosave = content;
}
