/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:33:05 by chmassa           #+#    #+#             */
/*   Updated: 2022/11/22 16:33:04 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	if (count && size > SIZE_MAX / count)
		return (NULL);
	i = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	else
	{
		while (i < count * size)
		{
			ptr[i] = '\0';
			i++;
		}
	}
	return (ptr);
}
