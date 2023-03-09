/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:11:25 by chmassa           #+#    #+#             */
/*   Updated: 2022/11/16 10:48:06 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while ((((unsigned char *)s1)[i] != '\0'
		&& ((unsigned char *)s2)[i] != '\0')
			&& (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i])
			&& (i < n - 1))
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
