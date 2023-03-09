/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_linker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:38:06 by chmassa           #+#    #+#             */
/*   Updated: 2022/12/03 08:19:23 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_flag_linker(char flag, va_list list)
{
	int	pc;

	pc = 1;
	if (flag == 'd' || flag == 'i')
	pc = ft_print_di(va_arg(list, int));
	if (flag == 's')
	pc = ft_putstr_ptf(va_arg(list, char *));
	if (flag == 'c')
		ft_putchar(va_arg(list, int));
	if (flag == 'u')
	pc = ft_print_u(va_arg(list, unsigned int));
	if (flag == 'p')
	{
		pc = ft_putstr_ptf("0x");
		pc += ft_print_p(va_arg(list, unsigned long long), "0123456789abcdef");
	}
	if (flag == 'x')
	pc = ft_print_x(va_arg(list, unsigned int), "0123456789abcdef");
	if (flag == 'X')
	pc = ft_print_x(va_arg(list, unsigned int),
				"0123456789ABCDEF");
	if (flag == '%')
		ft_putchar('%');
	return (pc);
}
