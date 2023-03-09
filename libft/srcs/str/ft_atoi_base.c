/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:44:09 by chmassa           #+#    #+#             */
/*   Updated: 2023/01/17 18:11:00 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_atoi_b(const char *str)
{
	long long	nb;
	int			i;
	int			sign;

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

static void	ft_base(long long nbr, const char *base)
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
		ft_base(nb / ft_strlen(base), base);
		ft_base(nb % ft_strlen(base), base);
	}
}

static int	parsing(const char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (ft_strlen(s) < 2)
		return (0);
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\r'
			|| s[i] == '\v' || s[i] == '-' || s[i] == '+')
			return (0);
		while (s[j])
		{
			if (s[i] == s[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	ft_atoi_base(const char *str, const char *base)
{
	long long	nb;

	if (!parsing(base))
		return (0);
	nb = ft_atoi_b(str);
	ft_base(nb, base);
	return (1);
}
