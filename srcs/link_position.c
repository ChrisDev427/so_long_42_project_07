/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:14:26 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/22 16:40:22 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	link_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->parse.mapcpy[y])
	{
		while (game->parse.mapcpy[y][x])
		{
			if (game->parse.mapcpy[y][x] == 'P')
			{
				game->win.y = y;
				game->win.x = x;
				game->win.py = y * 32;
				game->win.px = x * 32;
			}
			x++;
		}
		y++;
		x = 0;
	}	
}
