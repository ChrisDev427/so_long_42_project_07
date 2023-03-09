/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fire.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:07:11 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 18:25:00 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_print_fire(t_game *game)
{
	int	y;
	int	x;

	if (!(game->frame % 6))
		game->i_fire++;
	if (game->i_fire >= 4)
		game->i_fire = 0;
	y = 0;
	x = 0;
	while (game->mapcpy[y])
	{
		while (game->mapcpy[y][x])
		{
			if (game->mapcpy[y][x] == 'y')
				ft_print_img(game, game->fire[game->i_fire], x * 64,
					y * 64 -64);
			x++;
		}
		y++;
		x = 0;
	}
}
