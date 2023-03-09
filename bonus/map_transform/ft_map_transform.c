/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:43:39 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 18:14:19 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	replace_0_whith_space(t_game *game, int y, int x)
{
	while (game->mapcpy[y])
	{
		while (game->mapcpy[y][x])
		{
			if (game->mapcpy[y][x] == '0')
				game->mapcpy[y][x] = ' ';
			if (game->mapcpy[y][x] == '1')
				game->mapcpy[y][x] = BRICK;
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_map_transform(t_game *game)
{
	game->mapcpy = ft_strtab_dup(game->map);
	game->walls_elem = "abcdopqrnswemy /134";
	game->obj_elem = "0EPCKBS";
	map_initializer(game, 0, 0);
	replace_0_whith_space(game, 0, 0);
}
