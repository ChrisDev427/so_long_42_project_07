/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:16:05 by chmassa           #+#    #+#             */
/*   Updated: 2023/01/17 18:20:30 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long nbr, const char *base)
{
	unsigned long	nb;

	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	nb = nbr;
	if (nb < ft_strlen(base))
		write(1, &base[nb], 1);
	else
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putnbr_base(nb % ft_strlen(base), base);
	}
}
