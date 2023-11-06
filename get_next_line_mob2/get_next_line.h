/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:29:37 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/05 21:39:27 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //--------------
# include <string.h>
# include <fcntl.h>

# define _ERROR -1
# define _EOF 0

int		save_to_buff(int fd, char **buff, char **save);
char	*ft_strchr(char *save, char c);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
void	*ft_calloc(int count, int size);
char	*ft_strjoin(char *str1, char *str2);
char	*get_right(char *save);
char	*get_left(char *save, int flag);
char	*ft_strdup(char *s1);

#endif