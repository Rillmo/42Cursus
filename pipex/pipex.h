/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:22:33 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/30 20:12:09 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct s_cmd
{
	char	*path;
	char	**cmds;
}	t_cmd;