/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_anim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:38:50 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 17:59:38 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	go_right(t_game *game)
{
	if (!(game->frame % 4))
		game->i_link_rt++;
	if (game->i_link_rt >= 4)
		game->i_link_rt = 0;
	ft_print_img(game, game->link_rt[game->i_link_rt], game->link_x -32,
		game->link_y -32);
}

static void	go_left(t_game *game)
{
	if (!(game->frame % 4))
		game->i_link_lt++;
	if (game->i_link_lt >= 4)
		game->i_link_lt = 0;
	ft_print_img(game, game->link_lt[game->i_link_lt], game->link_x -32,
		game->link_y -32);
}

static void	go_up(t_game *game)
{
	if (!(game->frame % 4))
		game->i_link_up++;
	if (game->i_link_up >= 4)
		game->i_link_up = 0;
	ft_print_img(game, game->link_bk[game->i_link_up], game->link_x -32,
		game->link_y -32);
}

static void	go_down(t_game *game)
{	
	if (!(game->frame % 4))
		game->i_link_dn++;
	if (game->i_link_dn >= 4)
		game->i_link_dn = 0;
	ft_print_img(game, game->link_fa[game->i_link_dn], game->link_x -32,
		game->link_y -32);
}

void	ft_link_anim(t_game *game, char c)
{
	if (c == 'r')
		go_right(game);
	if (c == 'l')
		go_left(game);
	if (c == 'u')
		go_up(game);
	if (c == 'd')
		go_down(game);
}
