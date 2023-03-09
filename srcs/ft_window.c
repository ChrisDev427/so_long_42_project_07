/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:12:01 by chris             #+#    #+#             */
/*   Updated: 2023/02/13 10:30:29 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window(t_game *game)
{
	size_t	len_x;
	int		y;

	y = 0;
	len_x = ft_strlen(game->parse.map[y]);
	while (game->parse.map[y])
	{
		if (ft_strlen(game->parse.map[y]) > len_x)
			len_x = ft_strlen(game->parse.map[y]);
		y++;
	}
	game->win.x = len_x * 32;
	game->win.y = y * 32;
}
