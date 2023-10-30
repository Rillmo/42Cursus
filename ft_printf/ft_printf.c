/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:29:56 by junkim2           #+#    #+#             */
/*   Updated: 2023/10/30 20:25:33 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    print_convert(char type, va_list list)
{
    int result;

    result = 0;
    if (type == 0)
        return (-1);
    else if (type == '%')
        result = write(1, "%", 2);
    else if (type == 's')
        result = ft_print_str(va_arg(list, char*));
    else if (type == 'p')
        result = ft_print_ptr(va_arg(list, void*));
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
    char	after;
    int     print_size;

    print_size = 0;
	va_start(list, args);
    i = 0;
	while (args[i] != 0)
	{
		if (args[i] == '%')
        {
			after = args[i + 1];
            print_size += print_convert(after, list);
            if (print_size < 0)
                return (0);
            i++;
        }
        else
            print_size += write(1, &args[i], 1);
		i++;
	}
    return (print_size);
}
