/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:22:13 by junkim2           #+#    #+#             */
/*   Updated: 2023/10/30 20:39:10 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_str(char *str)
{
    int write_size;

    write_size = 0;
    if (str == 0)
    {
        write_size = write(1, "(null)", 6);
        return (write_size);
    }
    write_size = write(1, str, ft_strlen(str));
    return (write_size);
}

int ft_print_ptr(void *ptr)
{
    int                 write_size;
    unsigned long long  addr;
    int		            i;
	char	            result[16];
	char	            *hex;

    addr = (unsigned long long)ptr;
	hex = "0123456789abcdef";
	i = 0;
    write_size = 0;
    write_size += write(1, "0x", 2);
	while (i < ft_get_hex_size(addr))
	{
		result[i++] = hex[addr % 16];
		addr /= 16;
	}
	i--;
	while (i >= 0)
		write_size += write(1, &result[i--], 1);
    return (write_size);
}

int ft_print_digit(int num, char type)
{
    int     write_size;
    char    *to_write;

    if (type == 'd' || type == 'i')
    {
        to_write = ft_itoa(num);
        write_size = write(1, to_write, ft_strlen(to_write));
        free(to_write);
    }
    else
        write_size = write(1, &num, 1);
    return (write_size);
}

int ft_print_unsigned(unsigned int num)
{
    int     write_size;
    char    *to_write;

    to_write = ft_itoa(num);
    write_size = write(1, to_write, ft_strlen(to_write));
    free(to_write);
    return (write_size);
}
