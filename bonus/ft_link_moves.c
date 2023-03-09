/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:57:41 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 17:59:41 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_link_moves(t_game *game)
{
	if (game->link_keys[0] == 'u')
		ft_walk_up(game);
	if (game->link_keys[1] == 'l')
		ft_walk_left(game);
	if (game->link_keys[2] == 'r')
		ft_walk_right(game);
	if (game->link_keys[3] == 'd')
		ft_walk_down(game);
}
