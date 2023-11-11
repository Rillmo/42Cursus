/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:35:56 by macbookpro        #+#    #+#             */
/*   Updated: 2023/11/12 00:11:10 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
 #ifndef BUFFER_SIZE
 # define BUFFER_SIZE 42
 #endif

# include <stdlib.h>
# include <unistd.h>
//==================//
#include <stdio.h>
#include <fcntl.h>
//==================//

# define _ERROR	0
# define _EOF	-1

typedef struct s_list
{
	char	*buff;
	int		total_size;
	int		current_size;
}	t_list;

char	*get_next_line(int fd);
char	*alloc_double(char *buff, int alloc_size);
int		ft_strlen(char *str);
void	*ft_calloc(int count, int size);
char	*ft_strchr(char *str, char c);
char	*ft_strdup(char *s1);
char	*err_handler(t_list *lst);

#endif