/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:35:40 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/18 21:19:38 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	i_to_arr(long long n, char *result, size_t digit)
{
	if (!digit || result[digit - 1] == '-')
		return ;
	if (n < 0)
		result[digit - 1] = (n % 10) * -1 + '0';
	else
		result[digit - 1] = (n % 10) + '0';
	i_to_arr(n / 10, result, digit - 1);
}

static size_t	get_digit(long long n)
{
	size_t	digit;

	digit = 0;
	if (n <= 0)
		digit++;
	while (n != 0)
	{
		digit++;
		n /= 10;
	}
	return (digit);
}

char	*my_itoa(long long n)
{
	size_t	digit;
	char	*result;

	digit = get_digit(n);
	result = (char *)ft_calloc((digit + 1), sizeof(char));
	if (result == 0)
		return (0);
	if (n < 0)
		result[0] = '-';
	i_to_arr(n, result, digit);
	return (result);
}
