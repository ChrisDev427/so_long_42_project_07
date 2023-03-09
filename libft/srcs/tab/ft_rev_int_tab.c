/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 07:32:41 by chmassa           #+#    #+#             */
/*   Updated: 2022/11/27 18:26:46 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rev_int_tab(int *tab, size_t size)
{
	size_t	i;
	size_t	dn;
	size_t	tmp;

	if (size <= 1 || !tab)
		return ;
	i = 0;
	dn = size - 1;
	while (dn >= size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[dn];
		tab[dn] = tmp;
		i++;
		dn--;
	}
}
