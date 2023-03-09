/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_title.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:36:58 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/09 11:11:27 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_title(t_game *game)
{
	int	y;
	int	x;

	system("afplay -v 2 ./music/zelda_theme.mp3 &");
	y = 0;
	x = 0;
	while (game->mapcpy[y])
	{
		x = 0;
		while (game->mapcpy[y][x])
		{
			ft_print_img(game, game->gold_bg, x * 64, y * 64);
			x++;
		}
		y++;
	}
	ft_print_img(game, game->title, (x / 2) * 64 -180, (y / 2) * 64 -128);
}
