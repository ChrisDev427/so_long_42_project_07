/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:02:46 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 16:52:24 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_game *game, char *s)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	free_str_tab(game->parse.map);
	exit (EXIT_FAILURE);
}
