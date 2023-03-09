/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:56:02 by chmassa           #+#    #+#             */
/*   Updated: 2022/11/22 15:20:46 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_var
{
	size_t	i;
	size_t	word_len;
	size_t	str_nb;
	size_t	nb_words;
}				t_var;

static size_t	ft_nb_words(char *s, char c)
{
	t_var	v;

	v.i = 0;
	v.nb_words = 0;
	while (s[v.i])
	{
		if (s[v.i] != c)
		{
			v.nb_words++;
			while (s[v.i] && s[v.i] != c)
				v.i++;
		}
		else
			v.i++;
	}
	return (v.nb_words);
}

static char	**ft_fill_strs(char **strs, char *s, char c)
{
	t_var	v;

	v.i = 0;
	v.word_len = 0;
	v.str_nb = 0;
	while (s[v.i])
	{
		if (s[v.i] != c)
		{
			while (s[v.i] && s[v.i] != c)
			{
				v.word_len++;
				v.i++;
			}
			strs[v.str_nb] = ft_substr(s, v.i - v.word_len, v.word_len);
			if (!strs[v.str_nb])
				return (NULL);
			v.word_len = 0;
			v.str_nb++;
		}
		else
			v.i++;
	}
	strs[v.str_nb] = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = malloc(sizeof(char *) * (ft_nb_words((char *)s, c) + 1));
	if (!strs)
		return (NULL);
	if (!ft_fill_strs(strs, (char *)s, c))
		return (NULL);
	return (strs);
}
