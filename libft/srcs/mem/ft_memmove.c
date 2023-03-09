/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:16:32 by chmassa           #+#    #+#             */
/*   Updated: 2022/11/16 10:38:20 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*str_dst;
	const char	*str_src;
	size_t		i;

	i = 0;
	if (!dst && !src)
		return (0);
	str_dst = dst;
	str_src = src;
	if (dst < src)
	{
		while (i < len)
		{
			str_dst[i] = str_src[i];
			i++;
		}
	}
	else
		while (len-- > 0)
			str_dst[len] = str_src[len];
	return (dst);
}
