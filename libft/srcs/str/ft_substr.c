/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 08:46:05 by chmassa           #+#    #+#             */
/*   Updated: 2022/11/22 11:11:46 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_max(char const *s, size_t start, size_t len)
{
	unsigned int	i;
	unsigned int	max_len;
	unsigned int	slen;

	i = start;
	max_len = 0;
	slen = ft_strlen(s);
	if (start > slen)
		return (max_len);
	while (s[i] && i < (len + start))
	{
		i++;
		max_len++;
	}
	return (max_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	str_len;

	i = 0;
	if (!s)
		return (0);
	str_len = ft_len_max(s, start, len);
	str = malloc(sizeof(char) * str_len + 1);
	if (!str)
		return (NULL);
	while (i < len && i < str_len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
