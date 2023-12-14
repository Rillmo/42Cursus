/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:25:58 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/14 22:03:16 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

# include <stdio.h>
# include <string.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_data
{
	int			num;
	long long	idx;
	char		*base3;
}	t_data;

typedef struct s_stack
{
	t_data			*data;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info
{
	t_stack	*a;
	t_stack	*b;
	t_data	**origin;
	t_data	**sorted;
	int		max_len;
	int		argc;
	char	**argv;
	int		size;
}	t_info;

// === manual_sorting ===
void	man_sorting(t_info *info);
// === execption ===
void	check_input_err(int argc, char **argv);
void	check_dup_err(t_info *info);
// === parsing ===
int		count_digit(char *str);
// === setting ===
void	set_origin(t_info *info, int argc, char **argv);
void	indexing(t_data **arr, int size);
void	save_to_sorted(t_info *info);
// === util ====
int		get_3base_len(int n);
t_data	**parse_argv(t_info *info);
void	conv_3base(t_info *info, t_data **arr);
int		get_max_len(t_data **arr, int size);
int		is_sign(char c);
int		is_space(char c);
// ==== stack_util ====
t_stack	*get_newnode(t_data *data);
t_stack	*get_lastnode(t_stack *stack);
int		get_stacksize(t_stack *stack);
void	stack_addfront(t_stack **stack, t_data *data);
t_data	*stack_delfirst(t_stack **stack);
// ==== stack_func ====
void	pa(t_info *info, int print);
void	pb(t_info *info, int print);
void	sa(t_info *info, int print);
void	sb(t_info *info, int print);
void	ra(t_info *info, int print);
void	rb(t_info *info, int print);
void	rra(t_info *info, int print);
void	rrb(t_info *info, int print);
void	print_(t_info *info);
// ==== sort ====
void	sort_3base(t_info *info, int print);
void	move_to_a(t_info *info, int print);
int		is_sorted(t_info *info);

#endif