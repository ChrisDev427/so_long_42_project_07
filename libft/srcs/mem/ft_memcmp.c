/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:38:56 by chmassa           #+#    #+#             */
/*   Updated: 2022/11/16 10:42:56 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (0);
	if (!s1 && !s2)
		return (0);
	while ((((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			&& (i < n - 1))
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
