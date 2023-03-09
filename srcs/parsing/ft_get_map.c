/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:19:20 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/24 13:58:34 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count_lines(int fd)
{
	int		i;
	char	*s;

	i = 0;
	while (1)
	{
		s = get_next_line(fd);
		free(s);
		if (!s)
			break ;
		i++;
	}
	return (i);
}

static void	ft_fill(t_game *game, char *s, int i, int j)
{
	while (s[j])
	{
		game->parse.map[i][j] = s[j];
		j++;
	}
	if (game->parse.map[i][j -1] == '\n')
		game->parse.map[i][j -1] = '\0';
	else
			game->parse.map[i][j] = '\0';
}

static void	ft_get(t_game *game)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (1)
	{
		s = get_next_line(game->parse.fd);
		if (!s)
		{
			game->parse.map[i] = 0;
			break ;
		}
		game->parse.map[i] = malloc(sizeof(char) * (ft_strlen(s) + 1));
		ft_fill(game, s, i, j);
		i++;
		j = 0;
		free(s);
	}
}

void	ft_get_map(char *file, t_game *game)
{
	int		map_lines;

	ft_open(file, &game->parse.fd);
	map_lines = ft_count_lines(game->parse.fd);
	game->parse.map = malloc(sizeof(char *) * (map_lines + 1));
	ft_open(file, &game->parse.fd);
	ft_get(game);
}
