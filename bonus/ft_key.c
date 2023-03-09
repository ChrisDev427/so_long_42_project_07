/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 08:46:30 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 09:12:14 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_keyrelease(int key, t_game *game)
{
	if (key == 13)
		game->link_keys[0] = '0';
	if (key == 0)
		game->link_keys[1] = '0';
	if (key == 2)
		game->link_keys[2] = '0';
	if (key == 1)
		game->link_keys[3] = '0';
	if (key == 126)
		game->blob_keys[0] = '0';
	if (key == 123)
		game->blob_keys[1] = '0';
	if (key == 124)
		game->blob_keys[2] = '0';
	if (key == 125)
		game->blob_keys[3] = '0';
	return (0);
}

int	ft_keypress(int key, t_game *game)
{
	if (key == 36)
		game->start_game = 1;
	if (key == 53)
		ft_quit(game);
	if (key == 13)
		game->link_keys[0] = 'u';
	if (key == 0)
		game->link_keys[1] = 'l';
	if (key == 2)
		game->link_keys[2] = 'r';
	if (key == 1)
		game->link_keys[3] = 'd';
	if (key == 126)
		game->blob_keys[0] = 'u';
	if (key == 123)
		game->blob_keys[1] = 'l';
	if (key == 124)
		game->blob_keys[2] = 'r';
	if (key == 125)
		game->blob_keys[3] = 'd';
	return (0);
}
