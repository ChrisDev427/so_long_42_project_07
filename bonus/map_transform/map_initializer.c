/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:14:08 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 18:54:09 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static int	*ft_check(t_game *game, int y, int x, int *tab)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = -1;
	k = 0;
	while (i < 2)
	{
		while (j < 2)
		{
			if (y + i < 0 || x + j < 0)
				tab[k] = 1;
			else if (!game->mapcpy[y + i] || !game->mapcpy[y + i][x + j]
			|| ft_strchr(game->walls_elem, game->mapcpy[y + i][x + j]))
				tab[k] = 1;
			else if (ft_strchr(game->obj_elem, game->mapcpy[y + i][x + j]))
				tab[k] = 0;
			j++;
			k++;
		}
		i++;
		j = -1;
	}
	return (tab);
}

static int	walls_checker(t_game *game, int y, int x)
{
	int	i;
	int	result;
	int	tab[9];

	i = 0;
	ft_check(game, y, x, tab);
	result = 0;
	while (i < 9)
	{
		result = result * 10 + tab[i];
		i++;
	}
	return (result);
}

static void	assign_inside(t_game *game, int y, int x, int id)
{
	if (id == 11011 || id == 1011111 || id == 11111 || id == 1011011
		|| id == 111011 || id == 10011011 || id == 10111011 || id == 100011011
		|| id == 1111011 || id == 11111110 || id == 110111011
		|| id == 110011011 || id == 100111011 || id == 101011111
		|| id == 110011111 || id == 110011 || id == 101111011)
		game->mapcpy[y][x] = TOP_LT_OUT_ANGL;
	if (id == 110110 || id == 100110110 || id == 110111 || id == 101110111
		|| id == 100110111 || id == 1111110 || id == 11110111 || id == 111110
		|| id == 10110110 || id == 101111110 || id == 10111110
		|| id == 1110110 || id == 100111110 || id == 11111110
		|| id == 11110110 || id == 110111011 || id == 101110110)
		game->mapcpy[y][x] = TOP_RT_OUT_ANGL;
	if (id == 11111000 || id == 11011001 || id == 111011001 || id == 111011000
		|| id == 11011000 || id == 11111100 || id == 11011010 || id == 11111010
		|| id == 11011100 || id == 11111110 || id == 11011110 || id == 11111001
		|| id == 111011101 || id == 111011010)
		game->mapcpy[y][x] = BT_LT_OUT_ANGL;
	if (id == 110110000 || id == 110110100 || id == 111110000
		|| id == 111110100 || id == 110111000 || id == 110110010
		|| id == 110111010 || id == 110110001 || id == 110111011
		|| id == 110110011 || id == 110111001 || id == 111110101
		|| id == 111110010)
		game->mapcpy[y][x] = BT_RT_OUT_ANGL;
	if (id == 111111111)
		game->mapcpy[y][x] = ROOF;
}

static void	assign_surround(t_game *game, int y, int x, int id)
{
	if (id == 111111110)
		game->mapcpy[y][x] = TOP_LT_IN_ANGL;
	if (id == 111111011)
		game->mapcpy[y][x] = TOP_RT_IN_ANGL;
	if (id == 110111111)
		game->mapcpy[y][x] = BT_LT_IN_ANGL;
	if (id == 11111111)
		game->mapcpy[y][x] = BT_RT_IN_ANGL;
	if (id == 111111000 || id == 111111001 || id == 111111100
		|| id == 111111010 || id == 111111101)
		game->mapcpy[y][x] = N_WALL;
	if (id == 110110110 || id == 111110110 || id == 110110111
		|| id == 111110111 || id == 110111110)
		game->mapcpy[y][x] = W_WALL;
	if (id == 11011011 || id == 111011011 || id == 11011111
		|| id == 111011111 || id == 11111011)
		game->mapcpy[y][x] = E_WALL;
	if (id == 111111 || id == 100111111 || id == 1111111
		|| id == 10111111 || id == 101111111)
		game->mapcpy[y][x] = S_WALL;
	assign_inside(game, y, x, id);
}

void	map_initializer(t_game *game, int y, int x)
{
	while (game->mapcpy[y])
	{
		while (game->mapcpy[y][x])
		{
			if (game->mapcpy[y][x] == '1')
				assign_surround(game, y, x, walls_checker(game, y, x));
			if (game->mapcpy[y][x] == 'S')
			{
				game->safe_y = y;
				game->safe_x = x;
			}
			x++;
		}
		y++;
		x = 0;
	}
}
