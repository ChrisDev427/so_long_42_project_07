/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_paths.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:24:57 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 17:16:08 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_scan(char **s, int x, int y)
{
	while (s[y])
	{
		while (s[y][x])
		{
			if (s[y][x] == '|' || s[y][x] == 'P')
			{
				if (s[y][x -1] == '0' || s[y][x -1] == 'C' || s[y][x -1] == 'E')
					s[y][x -1] = '|';
				if (s[y][x +1] == '0' || s[y][x +1] == 'C' || s[y][x +1] == 'E')
					s[y][x +1] = '|';
				if (s[y -1][x] == '0' || s[y -1][x] == 'C' || s[y -1][x] == 'E')
					s[y -1][x] = '|';
				if (s[y +1][x] == '0' || s[y +1][x] == 'C' || s[y +1][x] == 'E')
					s[y +1][x] = '|';
				s[y][x] = 'X';
				x = 0;
				y = 0;
				break ;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_check_valid_paths(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	game->parse.mapcpy = ft_strtab_dup(game->parse.map);
	ft_scan(game->parse.mapcpy, x, y);
	while (game->parse.mapcpy[y])
	{
		while (game->parse.mapcpy[y][x])
		{
			if (game->parse.mapcpy[y][x] == 'C'
				|| game->parse.mapcpy[y][x] == 'E')
			{
				free_str_tab(game->parse.mapcpy);
				ft_error(game, "invalid path map");
			}
			x++;
		}
		y++;
		x = 0;
	}
	free_str_tab(game->parse.mapcpy);
}
