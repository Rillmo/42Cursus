/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:13:20 by minjacho          #+#    #+#             */
/*   Updated: 2023/10/14 16:15:28 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*temp_d;
	char	*temp_s;

	i = 0;
	temp_d = (char *)dst;
	temp_s = (char *)src;
	if (src < dst)
	{
		i = 1;
		while (i <= len && (src || dst))
		{
			temp_d[len - i] = temp_s[len - i];
			i++;
		}
	}
	else
	{
		while (i < len && (src || dst))
		{
			temp_d[i] = temp_s[i];
			i++;
		}
	}
	return (dst);
}
