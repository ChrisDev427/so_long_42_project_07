/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:19:20 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 18:15:57 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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

static void	ft_fill_str(t_game *game)
{
	char	*s;

	while (1)
	{
		s = get_next_line(game->fd);
		if (!s)
		{
			game->map[game->i] = 0;
			break ;
		}
		game->map[game->i] = malloc(sizeof(char) * (ft_strlen(s) + 1));
		while (s[game->j])
		{
			game->map[game->i][game->j] = s[game->j];
			game->j++;
		}
		if (game->map[game->i][game->j -1] == '\n')
			game->map[game->i][game->j -1] = '\0';
		else
			game->map[game->i][game->j] = '\0';
		game->i++;
		game->j = 0;
		free(s);
	}
}

void	ft_get_map(char *file, t_game *game)
{
	int	map_lines;

	ft_open(file, &game->fd);
	map_lines = ft_count_lines(game->fd);
	game->map = malloc(sizeof(char *) * (map_lines + 1));
	ft_open(file, &game->fd);
	ft_fill_str(game);
}
