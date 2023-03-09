/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:46:18 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 11:52:32 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_strs(char **src, char **dst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
	{
		while (src[i][j])
		{
			dst[i][j] = src[i][j];
			j++;
		}
		dst[i][j] = '\0';
		i++;
		j = 0;
	}
	dst[i] = 0;
}

char	**ft_strtab_dup(char **tab)
{
	char	**strtab;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	strtab = malloc(sizeof(char *) * (i + 1));
	if (!strtab)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		strtab[i] = malloc(sizeof(char) * (ft_strlen(tab[i]) + 1));
		if (!strtab)
			return (NULL);
		i++;
	}
	fill_strs(tab, strtab);
	return (strtab);
}
