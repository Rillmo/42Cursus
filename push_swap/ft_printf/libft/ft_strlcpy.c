/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:52:56 by junkim2           #+#    #+#             */
/*   Updated: 2023/10/14 19:15:00 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int		src_size;
	size_t	i;

	src_size = ft_strlen(src);
	i = 0;
	if (size <= 0)
		return (src_size);
	while (src[i] != 0 && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_size);
}
//
//int main(void)
//{
//	char a[] = "abcdefg";
//	char b[] = "string234";
//	int result;
//
//	result = ft_strlcpy(a, b, 3);
//	printf("%s\n", a);
//	printf("%d", result);
//	return 0;
//}	
