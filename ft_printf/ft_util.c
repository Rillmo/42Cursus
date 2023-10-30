/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:35:40 by junkim2           #+#    #+#             */
/*   Updated: 2023/10/30 19:25:08 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}
static void	i_to_arr(int n, char *result, size_t digit)
{
	if (!digit || result[digit - 1] == '-')
		return ;
	if (n < 0)
		result[digit - 1] = (n % 10) * -1 + '0';
	else
		result[digit - 1] = (n % 10) + '0';
	i_to_arr(n / 10, result, digit - 1);
}

static size_t	get_digit(int n)
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

char	*ft_itoa(int n)
{
	size_t	digit;
	char	*result;

	digit = get_digit(n);
	result = (char *)malloc((digit + 1) * sizeof(char));
	if (!result)
		return (NULL);
    result[digit] = 0;
	if (n < 0)
		result[0] = '-';
	i_to_arr(n, result, digit);
	return (result);
}
