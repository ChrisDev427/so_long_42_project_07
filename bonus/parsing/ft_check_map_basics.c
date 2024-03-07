/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_basics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:38:43 by chmassa           #+#    #+#             */
/*   Updated: 2024/03/07 16:26:36 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	check_size(t_game *game)
{
	int	x;
	int	y;
	int	len;
	x = ft_strlen(game->map[0]);
	y = 0;
	while (game->map[y])
	{
		len = ft_strlen(game->map[y]);
		if (len != x)
			ft_error(game, "map shape error\n");
		y++;
	}
	if (x < 6 || y < 5)
		ft_error(game, "map size is too small\n");
	if (x > 45 || y > 17)
		ft_error(game, "map size is too big\n");
}

static void	walls_is_surrounding(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		if (game->map[i][j] != '1')
			ft_error(game, "map: must surrounded by walls !");
		while (game->map[i][j])
		{
			if (game->map[0][j] != '1')
				ft_error(game, "map: must surrounded by walls !");
			if (game->map[i + 1] == NULL && game->map[i][j] != '1')
				ft_error(game, "map: must surrounded by walls !");
			j++;
		}
		if (game->map[i][j - 1] != '1')
			ft_error(game, "map: must surrounded by walls !");
		j = 0;
		i++;
	}
}

static int	check_element(t_game *game, char c)
{
	int		i;
	int		j;
	int		k;
	char	*s;

	i = 0;
	j = 0;
	k = 0;
	s = "01EPCKBS";
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == c)
				k++;
			if (ft_found_char(s, game->map[i][j]) == 0)
				ft_error(game, "map must only contain : 01SEPCKB\n");
			j++;
		}
		j = 0;
		i++;
	}
	return (k);
}

static void	check_ruby(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
			{
				if (game->map[y][x +1] == 'C' || game->map[y][x -1] == 'C'
				|| game->map[y +1][x] == 'C' || game->map[y -1][x] == 'C')
					ft_error(game, "ruby's cannot be next to each other\n");
			}
				x++;
		}
		x = 0;
		y++;
	}
}

void	ft_check_map_basics(t_game *game)
{
	check_size(game);
	check_ruby(game);
	walls_is_surrounding(game);
	if (check_element(game, 'E') == 0 || check_element(game, 'E') > 1)
		ft_error(game, "Exit is missing or more than 1 !\n");
	if (check_element(game, 'K') == 0)
		ft_error(game, "Knight is missing or more than 1 !\n");
	if (check_element(game, 'C') == 0)
		ft_error(game, "item is missing !\n");
	if (check_element(game, 'P') == 0 || check_element(game, 'P') > 1)
		ft_error(game, "start position is missing or more than 1 !\n");
	if (check_element(game, 'S') == 0 || check_element(game, 'S') > 1)
		ft_error(game, "'safe' item is missing or more than 1 !\n");
	if (check_element(game, 'B') == 0 || check_element(game, 'B') > 1)
		ft_error(game, "'blob' item is missing or more than 1 !\n");
}
