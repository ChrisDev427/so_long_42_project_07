/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:20:53 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 18:14:32 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	collectible_count(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->collectibles_nbr++;
			j++;
		}
		j = 0;
		i++;
	}
}
