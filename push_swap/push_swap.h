/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:25:58 by junkim2           #+#    #+#             */
/*   Updated: 2023/12/11 20:15:44 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
// ===============
#include <stdio.h>
// ===============

# define INT_MAX 2147483647

typedef struct s_data
{
	char		*str;
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
	int		max_len;
}	t_info;

// === util ====
int		get_3base_len(int n);
t_data	*parse_data(char *str);
void	indexing(t_stack **stack, int argc);
int		get_max_len(t_stack *stack);
void	conv_3base(t_stack *stack);
// ==== stack_util ====
t_stack	*get_newnode(t_data *data);
t_stack	*get_lastnode(t_stack *stack);
int		get_stacksize(t_stack *stack);
void	stack_addfront(t_stack **stack, t_data *data);
void	stack_addback(t_stack **stack, t_data *data);
t_data	*stack_delfirst(t_stack **stack);
t_data	*stack_dellast(t_stack **stack);
// ==== stack_func ====
void	pa(t_info *info);
void	pb(t_info *info);
void	sa(t_info *info);
void	sb(t_info *info);
void	ra(t_info *info);
void	rb(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	print_(t_info *info);
// ==== sort ====
void	sort_3base(t_info *info);


#endif