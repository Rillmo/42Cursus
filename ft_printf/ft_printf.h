#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int     ft_printf(const char *args, ...);
int     ft_print_char(int c);
int     ft_print_str(char *str);
int     ft_print_ptr(void *ptr);
int     ft_print_digit(int num, char type);
int     ft_print_unsigned(unsigned int num);
int     ft_print_hex(int num, char type);
size_t	ft_strlen(const char *s);
char	   *ft_itoa(int n);
int      ft_get_hex_size(int n);

#endif