/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blob_anim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:38:50 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 17:58:48 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_blob_anim(t_game *game, char c)
{
	if (c == 'r' || c == 'l' || c == 'u' || c == 'd')
	{
		if (!(game->frame % 4))
			game->i_blob++;
		if (game->i_blob >= 2)
			game->i_blob = 0;
		ft_print_img(game, game->blob[game->i_blob], game->blob_x -32,
			game->blob_y -32);
	}	
}
