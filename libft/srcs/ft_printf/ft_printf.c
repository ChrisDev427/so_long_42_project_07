/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:32:49 by chmassa           #+#    #+#             */
/*   Updated: 2022/12/03 08:20:33 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		printed_chars;

	printed_chars = 0;
	i = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchar(s[i]);
			printed_chars++;
		}
		if (s[i] == '%')
		{
			printed_chars += ft_flag_linker(s[i + 1], list);
			i++;
		}
		i++;
	}
	va_end(list);
	return (printed_chars);
}
