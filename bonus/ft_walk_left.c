/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walk_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:31:15 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 18:26:00 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_handle_safe(t_game *game)
{
	system("afplay -v 1 ./music/secret.wav &");
	game->get_exit = 1;
	game->mapcpy[(game->link_y) / 64][(game->link_x -25) / 64] = 'O';
}

static void	ft_handle_collectibles(t_game *game)
{
	game->link_x -= 4;
	game->moves++;
	game->mapcpy[(game->link_y +14) / 64][(game->link_x -25) / 64] = ' ';
	game->mapcpy[(game->link_y -24) / 64][(game->link_x -25) / 64] = ' ';
	system("afplay -v 3 ./music/Get_Rupee.wav &");
	game->collected++;
}

void	ft_walk_left(t_game *game)
{
	if (game->mapcpy[(game->link_y +16) / 64][(game->link_x -25) / 64]
		== 'S' && game->mapcpy[(game->link_y) / 64][(game->link_x -25)
			/ 64] == 'S' && game->open_safe == 1)
		ft_handle_safe(game);
	if (game->mapcpy[(game->link_y +16) / 64][(game->link_x -25) / 64]
		== ' ' && game->mapcpy[(game->link_y) / 64][(game->link_x -25)
			/ 64] == ' ')
	{
		game->moves++;
		game->link_x -= 4;
	}
	if (game->mapcpy[(game->link_y +14) / 64][(game->link_x -25) / 64]
		== 'C' || game->mapcpy[(game->link_y -20) / 64][(game->link_x -25)
			/ 64] == 'C')
		ft_handle_collectibles(game);
	if (game->mapcpy[(game->link_y +16) / 65][(game->link_x -25) / 64]
		== 'E' && game->get_exit == 1)
			game->ending = 2;
	if (game->mapcpy[(game->link_y +14) / 64][(game->link_x -25) / 64]
		== 'K' || game->mapcpy[(game->link_y -20) / 64][(game->link_x -25)
			/ 64] == 'K')
			game->ending = 1;
}
