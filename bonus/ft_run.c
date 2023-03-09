/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:08:03 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 18:27:03 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	get_key(t_game *game)
{
	system("afplay -v 2 ./music/get_key.wav &");
	ft_print_img(game, game->safe_key, game->safe_x, game->safe_y);
	game->collectibles_nbr = 0;
	game->open_safe = 1;
}

int	ft_run(t_game *game)
{
	if (game->ending == 0 && game->start_game == 1)
	{
		game->frame++;
		if (game->frame > 100)
			game->frame = 0;
		if (game->collected == game->collectibles_nbr)
			get_key(game);
		ft_print_map(game, game->mapcpy);
		ft_print_knight_shadow(game);
		ft_print_stats(game);
		ft_blob_moves(game);
		ft_link_moves(game);
		ft_link(game);
		ft_blob(game);
		ft_print_knight(game);
		ft_print_fire(game);
	}
	else if (game->ending == 1)
		ft_loose(game);
	else if (game->ending == 2)
		ft_win(game);
	return (0);
}
