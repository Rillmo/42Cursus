/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:25:58 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/18 21:45:42 by junkim2          ###   ########.fr       */
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

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

#endif