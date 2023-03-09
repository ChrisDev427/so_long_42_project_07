/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:47:01 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 17:35:12 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_quit(t_game *game)
{
	mlx_destroy_window(game->win.mlx_ptr, game->win.win_ptr);
	free_str_tab(game->parse.map);
	exit(EXIT_SUCCESS);
	return (0);
}
