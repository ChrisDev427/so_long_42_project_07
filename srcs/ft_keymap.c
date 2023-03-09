/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keymap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:57:41 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/24 14:36:56 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	walk_right(t_game *game)
{
	if (game->parse.mapcpy[game->win.y][game->win.x +1] == 'E'
		&& game->win.collected == game->win.collectibles_nbr)
		ft_quit(game);
	if (game->parse.mapcpy[game->win.y][game->win.x +1] != '1'
		&& game->parse.mapcpy[game->win.y][game->win.x +1] != 'E')
	{
		if (game->parse.mapcpy[game->win.y][game->win.x +1] == 'C')
		{
			game->parse.mapcpy[game->win.y][game->win.x +1] = '0';
			game->win.collected++;
		}
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->img.floor, game->win.px, game->win.py);
		game->win.px += 32;
		game->win.x += 1;
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->img.link_right, game->win.px, game->win.py);
	}
	game->img.moves++;
}

static void	walk_left(t_game *game)
{
	if (game->parse.mapcpy[game->win.y][game->win.x -1] == 'E'
		&& game->win.collected == game->win.collectibles_nbr)
		ft_quit(game);
	if (game->parse.mapcpy[game->win.y][game->win.x -1] != '1'
		&& game->parse.mapcpy[game->win.y][game->win.x -1] != 'E')
	{
		if (game->parse.mapcpy[game->win.y][game->win.x -1] == 'C')
		{
			game->parse.mapcpy[game->win.y][game->win.x -1] = '0';
			game->win.collected++;
		}
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->img.floor, game->win.px, game->win.py);
		game->win.px -= 32;
		game->win.x -= 1;
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->img.link_left, game->win.px, game->win.py);
	}
	game->img.moves++;
}

static void	walk_up(t_game *game)
{
	if (game->parse.mapcpy[game->win.y -1][game->win.x] == 'E'
		&& game->win.collected == game->win.collectibles_nbr)
		ft_quit(game);
	if (game->parse.mapcpy[game->win.y -1][game->win.x] != '1'
		&& game->parse.mapcpy[game->win.y -1][game->win.x] != 'E')
	{
		if (game->parse.mapcpy[game->win.y -1][game->win.x] == 'C')
		{
			game->parse.mapcpy[game->win.y -1][game->win.x] = '0';
			game->win.collected++;
		}
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->img.floor, game->win.px, game->win.py);
		game->win.py -= 32;
		game->win.y -= 1;
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->img.link_back, game->win.px, game->win.py);
	}
	game->img.moves++;
}

static void	walk_down(t_game *game)
{
	if (game->parse.mapcpy[game->win.y +1][game->win.x] == 'E'
		&& game->win.collected == game->win.collectibles_nbr)
		ft_quit(game);
	if (game->parse.mapcpy[game->win.y +1][game->win.x] != '1'
		&& game->parse.mapcpy[game->win.y +1][game->win.x] != 'E')
	{
		if (game->parse.mapcpy[game->win.y +1][game->win.x] == 'C')
		{
			game->parse.mapcpy[game->win.y +1][game->win.x] = '0';
			game->win.collected++;
		}
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->img.floor, game->win.px, game->win.py);
		game->win.py += 32;
		game->win.y += 1;
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->img.link_face, game->win.px, game->win.py);
	}
	game->img.moves++;
}

int	ft_keymap(int key, t_game *game)
{
	if (key == 53)
		ft_quit(game);
	if (key == 13)
		walk_up(game);
	if (key == 0)
		walk_left(game);
	if (key == 2)
		walk_right(game);
	if (key == 1)
		walk_down(game);
	ft_printf("moves = %d\n", game->img.moves);
	return (0);
}
