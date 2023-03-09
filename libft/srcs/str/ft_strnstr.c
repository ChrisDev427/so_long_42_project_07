/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:07:53 by chmassa           #+#    #+#             */
/*   Updated: 2022/11/18 15:36:30 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((!haystack) && len == 0)
		return (NULL);
	if (ft_strlen(needle) > ft_strlen(haystack) || (len < ft_strlen(needle)))
		return (NULL);
	if (((ft_strncmp(haystack, needle, len) == 0))
		|| (ft_strlen(needle) == 0))
		return ((char *)haystack);
	while (haystack[i] && len > 0 && (len >= ft_strlen(needle)))
	{
		if (haystack[i] == needle[j] && i < len)
		{
			if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0
				&& (i + ft_strlen(needle) <= len))
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
