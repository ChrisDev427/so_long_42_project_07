/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:30:56 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 17:19:56 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*init_img(t_game *game, char *file)
{
	void	*ptr;

	ptr = mlx_xpm_file_to_image(game->win.mlx_ptr, file, &game->win.img_wh,
			&game->win.img_ht);
	if (!ptr)
	{
		ft_error(game, "init xpm failed !\n");
		ft_quit(game);
	}
	return (ptr);
}

void	ft_init_sprites(t_game *game)
{
	game->img.link_face = init_img(game, "sprites/link_face.xpm");
	game->img.link_back = init_img(game, "sprites/link_back.xpm");
	game->img.link_left = init_img(game, "sprites/link_lt.xpm");
	game->img.link_right = init_img(game, "sprites/link_rt.xpm");
	game->img.floor = init_img(game, "sprites/floor.xpm");
	game->img.ruby = init_img(game, "sprites/ruby.xpm");
	game->img.exit = init_img(game, "sprites/exit.xpm");
	game->img.wall = init_img(game, "sprites/wall.xpm");
}
