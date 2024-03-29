/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:19:20 by chmassa           #+#    #+#             */
/*   Updated: 2024/03/07 16:25:26 by chris            ###   ########.fr       */
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
	close(fd);
	return (i);
}

static void	ft_fill_str(t_game *game)
{
	char	*s;
	game->i = 0;
	game->j = 0;
		
	while (1)
	{
		s = get_next_line(game->fd);
		
		if (!s)
		{
			game->map[game->i] = NULL;
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
