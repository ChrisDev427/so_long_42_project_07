/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_int_tab2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:05:22 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/06 08:22:41 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_int_tab2d(int **tab, int size)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
