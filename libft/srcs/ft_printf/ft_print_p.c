/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:29:41 by chmassa           #+#    #+#             */
/*   Updated: 2022/12/03 08:19:46 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(unsigned long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_print_p(unsigned long long int n, char *base)
{
	if (n < ft_strlen(base))
		ft_putchar(base[n]);
	else
	{
		ft_print_p(n / ft_strlen(base), base);
		ft_print_p(n % ft_strlen(base), base);
	}
	return (ft_nblen(n));
}
