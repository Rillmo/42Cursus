/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:20:39 by junkim2           #+#    #+#             */
/*   Updated: 2023/10/18 22:26:34 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char **result;
	result = ft_split("hello!",' ');
	while (*result != 0)
		printf("%s", *result++);
	return 0;
}
