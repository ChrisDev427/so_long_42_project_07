/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/22 18:28:50 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print(t_game *game, int y, int x)
{
	if (game->parse.mapcpy[y][x] == '1')
		mlx_put_image_to_window (game->win.mlx_ptr, game->win.win_ptr,
			game->img.wall, x * 32, y * 32);
	if (game->parse.mapcpy[y][x] == '0')
		mlx_put_image_to_window (game->win.mlx_ptr, game->win.win_ptr,
			game->img.floor, x * 32, y * 32);
	if (game->parse.mapcpy[y][x] == 'C')
		mlx_put_image_to_window (game->win.mlx_ptr, game->win.win_ptr,
			game->img.ruby, x * 32, y * 32);
	if (game->parse.mapcpy[y][x] == 'E')
		mlx_put_image_to_window (game->win.mlx_ptr, game->win.win_ptr,
			game->img.exit, x * 32, y * 32);
	if (game->parse.mapcpy[y][x] == 'P')
		mlx_put_image_to_window (game->win.mlx_ptr, game->win.win_ptr,
			game->img.link_face, x * 32, y * 32);
}

void	ft_print_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->parse.mapcpy[y])
	{
		while (game->parse.mapcpy[y][x])
		{
			print(game, y, x);
			x++;
		}
		y++;
		x = 0;
	}	
}
