/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:35:56 by macbookpro        #+#    #+#             */
/*   Updated: 2023/11/11 01:38:55 by macbookpro       ###   ########.fr       */
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
//==================//

# define _ERROR	0
# define _EOF	-1

typedef struct  s_node
{
    char    		*buff;
	int				count_buffering;
    struct s_node 	*next;
    struct s_node 	*before;
} t_node;

char	*get_next_line(int fd);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strlen(char *str);
void	*ft_calloc(int count, int size);
char	*ft_strchr(char *str, char c);

#endif