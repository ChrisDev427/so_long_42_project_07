/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_paths.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:24:57 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 18:15:43 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	replace(char **s, int x, int y)
{	
	if (s[y][x -1] == '0' || s[y][x -1] == 'C' || s[y][x -1] == 'E'
		|| s[y][x -1] == 'S' || s[y][x -1] == 'B')
		s[y][x -1] = '|';
	if (s[y][x +1] == '0' || s[y][x +1] == 'C' || s[y][x +1] == 'E'
		|| s[y][x +1] == 'S' || s[y][x +1] == 'B')
		s[y][x +1] = '|';
	if (s[y -1][x] == '0' || s[y -1][x] == 'C' || s[y -1][x] == 'E'
		|| s[y -1][x] == 'S' || s[y -1][x] == 'B')
		s[y -1][x] = '|';
	if (s[y +1][x] == '0' || s[y +1][x] == 'C' || s[y +1][x] == 'E'
		|| s[y +1][x] == 'S' || s[y +1][x] == 'B')
		s[y +1][x] = '|';
}

static void	ft_scan(char **s, int x, int y)
{
	while (s[y])
	{
		while (s[y][x])
		{
			if (s[y][x] == '|' || s[y][x] == 'P')
			{
				replace(s, x, y);
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
	game->mapcpy = ft_strtab_dup(game->map);
	ft_scan(game->mapcpy, x, y);
	while (game->mapcpy[y])
	{
		while (game->mapcpy[y][x])
		{
			if (game->mapcpy[y][x] == 'C' || game->mapcpy[y][x]
				== 'E' || game->mapcpy[y][x] == 'S'
					|| game->mapcpy[y][x] == 'B')
			{
				free_str_tab(game->mapcpy);
				ft_error(game, "invalide path map\n");
			}
			x++;
		}
		y++;
		x = 0;
	}
	free_str_tab(game->mapcpy);
}
