/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walk_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:31:09 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 18:26:08 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_handle_safe(t_game *game)
{
	system("afplay -v 1 ./music/secret.wav &");
	game->get_exit = 1;
	game->mapcpy[(game->link_y +25) / 64][(game->link_x -24) / 64] = 'O';
}

static void	ft_handle_collectibles(t_game *game)
{
	game->link_y += 4;
	game->moves++;
	game->mapcpy[(game->link_y +25) / 64][(game->link_x -12) / 64] = ' ';
	game->mapcpy[(game->link_y +25) / 64][(game->link_x) / 64] = ' ';
	system("afplay -v 3 ./music/Get_Rupee.wav &");
	game->collected++;
}

void	ft_walk_down(t_game *game)
{
	if (game->mapcpy[(game->link_y +25) / 64][(game->link_x -24) / 64]
		== 'S' && game->mapcpy[(game->link_y +25) / 64][(game->link_x)
			/ 64] == 'S' && game->open_safe == 1)
		ft_handle_safe(game);
	if (game->mapcpy[(game->link_y +25) / 64][(game->link_x -24) / 64]
		== ' ' && game->mapcpy[(game->link_y +25) / 64][(game->link_x)
			/ 64] == ' ')
	{
		game->link_y += 4;
		game->moves++;
	}
	if (game->mapcpy[(game->link_y +25) / 64][(game->link_x -12) / 64]
		== 'C' || game->mapcpy[(game->link_y +25) / 64][(game->link_x)
			/ 64] == 'C')
		ft_handle_collectibles(game);
	if (game->mapcpy[(game->link_y +25) / 64][(game->link_x -24) / 64]
		== 'E'
		&& game->get_exit == 1)
			game->ending = 2;
}
