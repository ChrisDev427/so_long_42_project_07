/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:20:53 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/22 18:38:46 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectible_count(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->parse.map[i])
	{
		while (game->parse.map[i][j])
		{
			if (game->parse.map[i][j] == 'C')
				game->win.collectibles_nbr++;
			j++;
		}
		j = 0;
		i++;
	}
}
