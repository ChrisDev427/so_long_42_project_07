/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_players.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:14:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/07 17:40:49 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_link(t_game *game)
{
	if (game->link_keys[0] == '0' && game->link_keys[1] == '0'
		&& game->link_keys[2] == '0'
		&& game->link_keys[3] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->link_fa[0], game->link_x -32, game->link_y -32);
	if (game->link_keys[0] == 'u')
		ft_link_anim(game, 'u');
	else if (game->link_keys[1] == 'l')
		ft_link_anim(game, 'l');
	else if (game->link_keys[2] == 'r')
		ft_link_anim(game, 'r');
	else if (game->link_keys[3] == 'd')
		ft_link_anim(game, 'd');
}

void	ft_blob(t_game *game)
{
	if (game->blob_keys[0] == '0' && game->blob_keys[1] == '0'
		&& game->blob_keys[2] == '0'
		&& game->blob_keys[3] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->blob[0], game->blob_x -32, game->blob_y -32);
	if (game->blob_keys[0] == 'u')
		ft_blob_anim(game, 'u');
	else if (game->blob_keys[1] == 'l')
		ft_blob_anim(game, 'l');
	else if (game->blob_keys[2] == 'r')
		ft_blob_anim(game, 'r');
	else if (game->blob_keys[3] == 'd')
		ft_blob_anim(game, 'd');
}
