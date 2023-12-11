/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:22:14 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/10 18:56:42 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipepack	pipepack;

	if (argc < 5 || (ft_strnstr(argv[1], "here_doc", 8) && argc < 6))
		exit_with_err();
	set_pipepack(&pipepack, argc, argv, envp);
	get_path_list(&pipepack);
	if (ft_strnstr(argv[1], "here_doc", 8) != NULL)
	{
		here_doc(&pipepack);
		exit(EXIT_SUCCESS);
	}
	connect_pipe(&pipepack);
}
