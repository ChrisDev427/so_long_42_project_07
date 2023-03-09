/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strs_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:32:05 by chmassa           #+#    #+#             */
/*   Updated: 2022/11/27 19:18:09 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_strs_array(char **strs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!strs)
		return ;
	while (strs[i])
	{
		while (strs[i][j])
		{
			write (1, &strs[i][j], 1);
		j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}
