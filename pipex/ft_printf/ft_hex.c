/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:23:23 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/01 15:08:40 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_hex_size(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len + 1);
}

static char	*hex_helper(unsigned int n, char type)
{
	char	*result;
	int		i;
	int		len;

	len = ft_get_hex_size(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	i = 0;
	if (n == 0)
		result[i++] = '0';
	while (n != 0)
	{
		if (type == 'x')
			result[i] = "0123456789abcdef"[n % 16];
		else
			result[i] = "0123456789ABCDEF"[n % 16];
		n /= 16;
		i++;
	}
	result[i] = 0;
	return (result);
}

int	ft_print_hex(unsigned int num, char type)
{
	int		i;
	char	*to_write;
	int		write_size;
	int		total_size;

	i = 0;
	total_size = 0;
	to_write = hex_helper(num, type);
	if (to_write == 0)
		return (-1);
	i = ft_strlen(to_write) - 1;
	while (i >= 0)
	{
		write_size = write(1, &to_write[i--], 1);
		if (write_size < 0)
		{
			free(to_write);
			return (-1);
		}
		total_size += write_size;
	}
	free(to_write);
	return (total_size);
}
