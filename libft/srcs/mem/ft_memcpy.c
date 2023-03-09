/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:03:05 by chmassa           #+#    #+#             */
/*   Updated: 2022/11/11 16:45:16 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*strdst;
	const char	*strsrc;
	size_t		i;

	strdst = dst;
	strsrc = src;
	if ((!strdst) && (!strsrc))
		return (NULL);
	i = 0;
	while (i < n)
	{
		strdst[i] = strsrc[i];
		i++;
	}
	return (dst);
}
