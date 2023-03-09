/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:42:12 by chmassa           #+#    #+#             */
/*   Updated: 2022/11/16 10:40:08 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*str;

	i = 0;
	str = (char *)s;
	if (c == 0 && n == 0)
		return (NULL);
	if (c == 0 && n == 1)
		return ((void *)s);
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)(str + i));
	i++;
	}
	return (NULL);
}
