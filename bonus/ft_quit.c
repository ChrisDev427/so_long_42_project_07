/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:47:01 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/09 11:12:27 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_loose(t_game *game)
{
	int	y;
	int	x;

	if (game->ending == 1)
	{
		system("afplay -v 1 ./music/Fall.wav &");
		game->ending = 4;
	}
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
	ft_print_img(game, game->loose_img, (x / 2) * 64 -180, (y / 2) * 64 -128);
}

void	ft_win(t_game *game)
{
	int	y;
	int	x;

	if (game->ending == 2)
	{
		system("afplay -v 2 ./music/fanfare.wav &");
		game->ending = 3;
	}
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
	ft_print_img(game, game->win_img, (x / 2) * 64 -180, (y / 2) * 64 -128);
}

int	ft_quit(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	system("killall afplay 2> /dev/null");
	exit(EXIT_SUCCESS);
	return (0);
}
