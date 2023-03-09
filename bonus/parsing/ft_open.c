/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 08:36:41 by chris             #+#    #+#             */
/*   Updated: 2023/03/09 11:02:56 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static int	ft_check_ext(char *file)
{
	if (!ft_found_char(file, '.'))
		return (0);
	if (ft_strcmp(".ber", ft_strrchr(file, '.')) != 0)
		return (0);
	return (1);
}

void	ft_open(char *file, int *fd)
{
	if (!ft_check_ext(file))
	{
		ft_putstr_fd("map file must be '.ber' !\n", 2);
		system("leaks so_long_bonus");
		exit(EXIT_FAILURE);
	}
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
}
