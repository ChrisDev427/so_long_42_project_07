/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_players_positions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:14:26 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 18:24:05 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h" 

static void	link_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->mapcpy[y])
	{
		while (game->mapcpy[y][x])
		{
			if (game->mapcpy[y][x] == 'P')
			{
				game->link_y = y * 64 +32;
				game->link_x = x * 64 +32;
				game->mapcpy[y][x] = ' ';
			}
			x++;
		}
		y++;
		x = 0;
	}
}

static void	blob_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->mapcpy[y])
	{
		while (game->mapcpy[y][x])
		{
			if (game->mapcpy[y][x] == 'B')
			{
				game->blob_y = y * 64 +32;
				game->blob_x = x * 64 +32;
				game->mapcpy[y][x] = ' ';
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_players_positions(t_game *game)
{
	link_position(game);
	blob_position(game);
}
