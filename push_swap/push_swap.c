/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:30:13 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/19 18:31:47 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	*input;

	input = (int *)calloc(argc, sizeof(int));
	i = 1;
	while (i < argc)
	{
		input[i - 1] = atoi(argv[i]);
		i++;
	}
	for (int i=input[0]; i>=0; i--)
		ft_printf("%d", (input[0]>>i) & 1);
}
