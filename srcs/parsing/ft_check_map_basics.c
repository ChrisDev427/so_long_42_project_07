/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_basics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:38:43 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 17:34:42 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_size(t_game *game)
{
	int	x;
	int	y;
	int	len;

	x = ft_strlen(game->parse.map[0]);
	y = 0;
	while (game->parse.map[y])
	{
		len = ft_strlen(game->parse.map[y]);
		if (len != x)
			ft_error(game, "map shape error !");
		y++;
	}
	if (x > 60 || y > 33)
		ft_error(game, "map size is too big");
}

static void	walls_is_surrounding(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->parse.map[i])
	{
		if (game->parse.map[i][j] != '1')
			ft_error(game, "map: must surrounded by walls !");
		while (game->parse.map[i][j])
		{
			if (game->parse.map[0][j] != '1')
				ft_error(game, "map must surrounded by walls !");
			if (game->parse.map[i + 1] == NULL && game->parse.map[i][j] != '1')
				ft_error(game, "map must surrounded by walls !");
			j++;
		}
		if (game->parse.map[i][j - 1] != '1')
			ft_error(game, "map must surrounded by walls !");
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
	s = "01CPE";
	while (game->parse.map[i])
	{
		while (game->parse.map[i][j])
		{
			if (game->parse.map[i][j] == c)
				k++;
			if (ft_found_char(s, game->parse.map[i][j]) == 0)
				ft_error(game, "map must only contain : 01EPC\n");
			j++;
		}
		j = 0;
		i++;
	}
	return (k);
}

void	ft_check_map_basics(t_game *game)
{
	check_size(game);
	walls_is_surrounding(game);
	if (check_element(game, 'E') == 0 || check_element(game, 'E') > 1)
		ft_error(game, "exit is missing or more than 1 !\n");
	if (check_element(game, 'C') == 0)
		ft_error(game, "collectible is missing !\n");
	if (check_element(game, 'P') == 0 || check_element(game, 'P') > 1)
		ft_error(game, "start position is missing or more than 1 !\n");
}
