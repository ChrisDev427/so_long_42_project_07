/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_knight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:40:16 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 18:26:47 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_print_knight_shadow(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->mapcpy[y])
	{
		while (game->mapcpy[y][x])
		{
			if (game->mapcpy[y][x] == 'K')
				ft_print_img(game, game->shadow[game->i_knight],
					x * 64 - 16, y * 64 - 80);
			x++;
		}
		y++;
		x = 0;
	}	
}

static void	print(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->mapcpy[y])
	{
		while (game->mapcpy[y][x])
		{
			if (game->mapcpy[y][x] == 'K')
				ft_print_img(game, game->knight[game->i_knight], x * 64 -16,
					y * 64 -80);
			x++;
		}
		y++;
		x = 0;
	}	
}

void	ft_print_knight(t_game *game)
{
	if (game->i_knight == 4 && game->sound_knight == 1)
	{
		game->sound_knight = 0;
		system("afplay -v 1 ./music/sound.mp3 &");
	}
	if (game->i_knight == 5)
		game->sound_knight = 1;
	if (!(game->frame % 20) && game->i_knight == 8)
		game->i_knight++;
	else if (!(game->frame % 40) && game->i_knight == 6)
			game->i_knight++;
	else if (!(game->frame % 8) && game->i_knight != 6 && game->i_knight != 8)
		game->i_knight++;
	if (game->i_knight >= 11)
		game->i_knight = 0;
	print(game);
}
