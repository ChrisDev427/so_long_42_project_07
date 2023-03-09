/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_roof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:16:52 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 18:24:37 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_print_roof(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->mapcpy[y])
	{
		while (game->mapcpy[y][x])
		{
			if (game->mapcpy[y][x] == '/')
				mlx_put_image_to_window (game->mlx, game->win,
					game->roof, x * 64, y * 64);
			x++;
		}
		y++;
		x = 0;
	}
}
