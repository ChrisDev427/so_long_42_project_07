/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:35:56 by chmassa           #+#    #+#             */
/*   Updated: 2023/02/22 18:38:13 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initial(t_game *game)
{
	game->win.mlx_ptr = mlx_init();
	game->win.win_ptr = mlx_new_window(game->win.mlx_ptr, game->win.x,
			game->win.y, "a Chris to the past");
	game->win.y = 0;
	game->win.x = 0;
	game->img.moves = 0;
	game->win.collectibles_nbr = 0;
	collectible_count(game);
	game->win.collected = 0;
}
