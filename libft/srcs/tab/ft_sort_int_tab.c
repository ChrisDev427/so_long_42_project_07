/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:28:20 by chmassa           #+#    #+#             */
/*   Updated: 2022/11/27 18:11:27 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_tab(int *tab, size_t size)
{
	size_t	i;
	size_t	j;
	int		tmp;

	if (!tab)
		return ;
	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
				j++;
			}
			else
			j++;
		}
		i++;
		j = i + 1;
	}
}
