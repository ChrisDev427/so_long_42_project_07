/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blob_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:57:41 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 18:25:16 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	walk_right(t_game *game)
{
	if (game->mapcpy[(game->blob_y +16) / 64][(game->blob_x +24) / 64] ==
		' ' && game->mapcpy[(game->blob_y) / 64][(game->blob_x) / 64]
		== ' ')
	{
		game->blob_x += 3;
		if ((game->blob_y +16) / 64 == game->link_y / 64 && (game->blob_x +24)
			/ 64 == game->link_x / 64)
			game->ending = 1;
	}
}

static void	walk_left(t_game *game)
{
	if (game->mapcpy[(game->blob_y +16) / 64][(game->blob_x -32) / 64] ==
		' ' && game->mapcpy[(game->blob_y) / 64][(game->blob_x -25) / 64]
		== ' ')
	{
		game->blob_x -= 3;
		if ((game->blob_y +16) / 64 == game->link_y / 64 && (game->blob_x -32)
			/ 64 == game->link_x / 64)
			game->ending = 1;
	}
}

static void	walk_up(t_game *game)
{
	if (game->mapcpy[(game->blob_y - 16) / 64][(game->blob_x -24) / 64] ==
		' ' && game->mapcpy[(game->blob_y - 16) / 64][(game->blob_x) / 64]
		== ' ')
	{
		game->blob_y -= 3;
		if ((game->blob_y -16) / 64 == game->link_y / 64 && (game->blob_x -24)
			/ 64 == game->link_x / 64)
			game->ending = 1;
	}
}

static void	walk_down(t_game *game)
{
	if (game->mapcpy[(game->blob_y +25) / 64][(game->blob_x -24) / 64] ==
		' ' && game->mapcpy[(game->blob_y +25) / 64][(game->blob_x) / 64]
		== ' ')
	{
		game->blob_y += 3;
		if ((game->blob_y +25) / 64 == game->link_y / 64 && (game->blob_x -24)
			/ 64 == game->link_x / 64)
			game->ending = 1;
	}
}

void	ft_blob_moves(t_game *game)
{
	if (game->blob_keys[0] == 'u')
		walk_up(game);
	if (game->blob_keys[1] == 'l')
		walk_left(game);
	if (game->blob_keys[2] == 'r')
		walk_right(game);
	if (game->blob_keys[3] == 'd')
		walk_down(game);
}
