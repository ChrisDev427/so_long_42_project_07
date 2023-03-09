/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_sprites_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:30:56 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 17:23:46 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	items1(t_game *game)
{
	game->floor = init_img(game, "bonus/xpm/floor.xpm");
	game->roof = init_img(game, "bonus/xpm/roof.xpm");
	game->safe_cl = init_img(game, "bonus/xpm/safe_cl.xpm");
	game->safe_op = init_img(game, "bonus/xpm/safe_op.xpm");
	game->safe_key = init_img(game, "bonus/xpm/safe_key.xpm");
	game->exit = init_img(game, "bonus/xpm/exit.xpm");
	game->green_bg = init_img(game, "bonus/xpm/green_bg.xpm");
	game->white_bg = init_img(game, "bonus/xpm/white_bg.xpm");
	game->gold_bg = init_img(game, "bonus/xpm/gold_bg.xpm");
	game->title = init_img(game, "bonus/xpm/title.xpm");
}

static void	items2(t_game *game)
{
	game->jar = init_img(game, "bonus/xpm/jar.xpm");
	game->fire[0] = init_img(game, "bonus/xpm/fire1.xpm");
	game->fire[1] = init_img(game, "bonus/xpm/fire2.xpm");
	game->fire[2] = init_img(game, "bonus/xpm/fire3.xpm");
	game->fire[3] = init_img(game, "bonus/xpm/fire4.xpm");
	game->ruby[0] = init_img(game, "bonus/xpm/rub1.xpm");
	game->ruby[1] = init_img(game, "bonus/xpm/rub2.xpm");
	game->ruby[2] = init_img(game, "bonus/xpm/rub3.xpm");
	game->blob[0] = init_img(game, "bonus/xpm/blob1.xpm");
	game->blob[1] = init_img(game, "bonus/xpm/blob2.xpm");
	game->loose_img = init_img(game, "bonus/xpm/ending_loose.xpm");
	game->win_img = init_img(game, "bonus/xpm/ending_win.xpm");
	game->stats_bg = init_img(game, "bonus/xpm/stats_bg.xpm");
	game->key = init_img(game, "bonus/xpm/key.xpm");
}

static void	walls(t_game *game)
{
	game->wall_n = init_img(game, "bonus/xpm/wall_n.xpm");
	game->wall_s = init_img(game, "bonus/xpm/wall_s.xpm");
	game->wall_e = init_img(game, "bonus/xpm/wall_e.xpm");
	game->wall_w = init_img(game, "bonus/xpm/wall_w.xpm");
	game->bt_rt = init_img(game, "bonus/xpm/bt_rt.xpm");
	game->bt_lt = init_img(game, "bonus/xpm/bt_lt.xpm");
	game->tp_rt = init_img(game, "bonus/xpm/tp_rt.xpm");
	game->tp_lt = init_img(game, "bonus/xpm/tp_lt.xpm");
	game->out_bt_rt = init_img(game, "bonus/xpm/out_bt_rt.xpm");
	game->out_bt_lt = init_img(game, "bonus/xpm/out_bt_lt.xpm");
	game->out_tp_rt = init_img(game, "bonus/xpm/out_tp_rt.xpm");
	game->out_tp_lt = init_img(game, "bonus/xpm/out_tp_lt.xpm");
}

static void	knight(t_game *game)
{
	game->knight[0] = init_img(game, "bonus/xpm/en1.xpm");
	game->knight[1] = init_img(game, "bonus/xpm/en2.xpm");
	game->knight[2] = init_img(game, "bonus/xpm/en3.xpm");
	game->knight[3] = init_img(game, "bonus/xpm/en4.xpm");
	game->knight[4] = init_img(game, "bonus/xpm/en5.xpm");
	game->knight[5] = init_img(game, "bonus/xpm/en6.xpm");
	game->knight[6] = init_img(game, "bonus/xpm/en7.xpm");
	game->knight[7] = init_img(game, "bonus/xpm/en8.xpm");
	game->knight[8] = init_img(game, "bonus/xpm/en9.xpm");
	game->knight[9] = init_img(game, "bonus/xpm/en10.xpm");
	game->knight[10] = init_img(game, "bonus/xpm/en11.xpm");
	game->knight[11] = init_img(game, "bonus/xpm/en12.xpm");
	game->shadow[0] = init_img(game, "bonus/xpm/sh1.xpm");
	game->shadow[1] = init_img(game, "bonus/xpm/sh2.xpm");
	game->shadow[2] = init_img(game, "bonus/xpm/sh3.xpm");
	game->shadow[3] = init_img(game, "bonus/xpm/sh4.xpm");
	game->shadow[4] = init_img(game, "bonus/xpm/sh5.xpm");
	game->shadow[5] = init_img(game, "bonus/xpm/sh6.xpm");
	game->shadow[6] = init_img(game, "bonus/xpm/sh7.xpm");
	game->shadow[7] = init_img(game, "bonus/xpm/sh8.xpm");
	game->shadow[8] = init_img(game, "bonus/xpm/sh9.xpm");
	game->shadow[9] = init_img(game, "bonus/xpm/sh10.xpm");
	game->shadow[10] = init_img(game, "bonus/xpm/sh11.xpm");
	game->shadow[11] = init_img(game, "bonus/xpm/sh12.xpm");
}

void	items_sprites_init(t_game *game)
{
	walls(game);
	items1(game);
	items2(game);
	knight(game);
}
