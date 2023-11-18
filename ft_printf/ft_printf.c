/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:18:05 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/01 14:59:39 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_convert(char type, va_list list)
{
	int	result;

	result = 0;
	if (type == 0)
		return (-1);
	else if (type == '%')
		result = write(1, "%", 1);
	else if (type == 's')
		result = ft_print_str(va_arg(list, char *));
	else if (type == 'p')
		result = ft_print_ptr(va_arg(list, void *));
	else if (type == 'd' || type == 'i' || type == 'c')
		result = ft_print_digit(va_arg(list, int), type);
	else if (type == 'u')
		result = ft_print_unsigned(va_arg(list, unsigned int));
	else if (type == 'x' || type == 'X')
		result = ft_print_hex(va_arg(list, int), type);
	else
		return (-1);
	return (result);
}

int	ft_printf(const char *args, ...)
{
	int		i;
	va_list	list;
	int		print_size;
	int		total_size;

	total_size = 0;
	va_start(list, args);
	i = 0;
	while (args[i] != 0)
	{
		if (args[i] == '%')
		{
			print_size = print_convert(args[i + 1], list);
			i++;
		}
		else
			print_size = write(1, &args[i], 1);
		if (print_size < 0)
			return (-1);
		total_size += print_size;
		i++;
	}
	va_end(list);
	return (total_size);
}
