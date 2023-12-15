/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:22:19 by macbookpro        #+#    #+#             */
/*   Updated: 2023/12/15 23:15:33 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>

# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_info
{
	int		argc;
	char	**argv;
	int		size;
	int		*input;
}	t_info;

// === parsing ===
int		count_digit(char *str);
int		*parse_argv(t_info *info);
// === util ===
int		is_space(char c);
int		is_sign(char c);
// === exception ===
void	check_input_err(int argc, char **argv);
void	check_dup_err(t_info *info);
void	exit_with_err(void);
void	check_valid_action(char *str);
// === setting ===
void	set_info(t_info *info, int argc, char **argv);
void	set_action(t_info *info);

#endif