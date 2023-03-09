/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 18:26:25 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	print_walls(t_game *game, char **s, int y, int x)
{
	if (s[y][x] == 'e')
		ft_print_img(game, game->wall_e, x * 64, y * 64);
	if (s[y][x] == 'n')
		ft_print_img(game, game->wall_n, x * 64, y * 64);
	if (s[y][x] == 'w')
		ft_print_img(game, game->wall_w, x * 64, y * 64);
	if (s[y][x] == 's')
		ft_print_img(game, game->wall_s, x * 64, y * 64);
	if (game->mapcpy[y][x] == ' ' || game->mapcpy[y][x] == 'K'
	|| game->mapcpy[y][x] == 'C')
		ft_print_img(game, game->floor, x * 64, y * 64);
	if (game->mapcpy[y][x] == 'E')
		ft_print_img(game, game->exit, x * 64, y * 64);
	if (game->mapcpy[y][x] == 'y')
		ft_print_img(game, game->jar, x * 64, y * 64);
	if (game->mapcpy[y][x] == 'C')
		ft_print_img(game, game->ruby[game->i_ruby], x * 64, y * 64);
	if (game->mapcpy[y][x] == 'S' && game->open_safe == 0)
	{
		ft_print_img(game, game->safe_cl, x * 64, y * 64);
		game->safe_x = x * 64;
		game->safe_y = y * 64;
	}
}

static void	print_corners(t_game *game, char **s, int y, int x)
{
	if (s[y][x] == 'a')
		ft_print_img(game, game->tp_lt, x * 64, y * 64);
	if (s[y][x] == 'b')
		ft_print_img(game, game->tp_rt, x * 64, y * 64);
	if (s[y][x] == 'c')
		ft_print_img(game, game->bt_lt, x * 64, y * 64);
	if (s[y][x] == 'd')
		ft_print_img(game, game->bt_rt, x * 64, y * 64);
	if (s[y][x] == 'o')
		ft_print_img(game, game->out_tp_lt, x * 64, y * 64);
	if (s[y][x] == 'q')
		ft_print_img(game, game->out_bt_lt, x * 64, y * 64);
	if (s[y][x] == 'p')
		ft_print_img(game, game->out_tp_rt, x * 64, y * 64);
	if (s[y][x] == 'r')
		ft_print_img(game, game->out_bt_rt, x * 64, y * 64);
	if (s[y][x] == '/')
		ft_print_img(game, game->roof, x * 64, y * 64);
	if (s[y][x] == 'O')
		ft_print_img(game, game->safe_op, x * 64, y * 64);
}

void	ft_print_map(t_game *game, char **s)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (!(game->frame % 8))
		game->i_ruby++;
	if (game->i_ruby >= 3)
		game->i_ruby = 0;
	while (s[y])
	{
		while (s[y][x])
		{
			print_walls(game, s, y, x);
			print_corners(game, s, y, x);
			x++;
		}
		y++;
		x = 0;
	}
}
