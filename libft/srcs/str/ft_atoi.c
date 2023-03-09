/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:34:31 by chmassa           #+#    #+#             */
/*   Updated: 2022/11/16 13:10:16 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	sign;

	i = 0;
	nb = 0;
	sign = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-' && str[i + 1] != '+')
	{
		sign++;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	if (sign != 0)
		nb = nb * -1;
	return (nb);
}
