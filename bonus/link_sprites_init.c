/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_sprites_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:21:50 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 18:00:53 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	link_init_1(t_game *game)
{
	game->link_fa[0] = init_img(game, "bonus/xpm/link_fa1.xpm");
	game->link_fa[1] = init_img(game, "bonus/xpm/link_fa2.xpm");
	game->link_fa[2] = init_img(game, "bonus/xpm/link_fa3.xpm");
	game->link_fa[3] = init_img(game, "bonus/xpm/link_fa4.xpm");
	game->link_bk[0] = init_img(game, "bonus/xpm/link_bk1.xpm");
	game->link_bk[1] = init_img(game, "bonus/xpm/link_bk2.xpm");
	game->link_bk[2] = init_img(game, "bonus/xpm/link_bk3.xpm");
	game->link_bk[3] = init_img(game, "bonus/xpm/link_bk4.xpm");
}

static void	link_init_2(t_game *game)
{
	game->link_lt[0] = init_img(game, "bonus/xpm/link_lt1.xpm");
	game->link_lt[1] = init_img(game, "bonus/xpm/link_lt2.xpm");
	game->link_lt[2] = init_img(game, "bonus/xpm/link_lt3.xpm");
	game->link_lt[3] = init_img(game, "bonus/xpm/link_lt4.xpm");
	game->link_rt[0] = init_img(game, "bonus/xpm/link_rt1.xpm");
	game->link_rt[1] = init_img(game, "bonus/xpm/link_rt2.xpm");
	game->link_rt[2] = init_img(game, "bonus/xpm/link_rt3.xpm");
	game->link_rt[3] = init_img(game, "bonus/xpm/link_rt4.xpm");
}

void	link_sprites_init(t_game *game)
{
	link_init_1(game);
	link_init_2(game);
}
