/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:47:38 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/01 17:12:41 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_with_err(void)
{
	perror(strerror(errno));
	exit(EXIT_FAILURE);
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
