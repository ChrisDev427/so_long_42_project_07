/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:03:58 by chmassa           #+#    #+#             */
/*   Updated: 2022/11/23 16:58:24 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] && set[j])
	{
		if (set[j] == s1[i])
		{
			i++;
			j = -1;
		}
	j++;
	}
	return (i);
}

static size_t	str_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (i > 0 && set[j])
	{
		if (set[j] == s1[i])
		{
			i--;
			j = -1;
		}
		j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = str_start(s1, set);
	end = str_end(s1, set);
	str = ft_substr(s1, start, (end - start) + 1);
	if (!str)
		return (NULL);
	return (str);
}
