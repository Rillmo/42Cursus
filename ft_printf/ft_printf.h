/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:10:41 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/18 21:19:45 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_printf(const char *args, ...);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_ptr(void *ptr);
int		ft_print_digit(int num, char type);
int		ft_print_unsigned(long long num);
int		ft_print_hex(unsigned int num, char type);
char	*my_itoa(long long n);
int		ft_get_hex_size(unsigned int n);

#endif
