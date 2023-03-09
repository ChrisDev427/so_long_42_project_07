/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:04:35 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/09 14:35:06 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_rupee_collect(t_game *game)
{
	char	*ruby;
	char	*str;

	str = "ruby ";
	ruby = ft_itoa(game->collected);
	str = ft_strjoin(str, ruby);
	free(ruby);
	mlx_string_put(game->mlx, game->win, 128, 4, 255 * 256 * 256, str);
	free(str);
}

static void	ft_print_moves(t_game *game)
{
	char	*retrieve_nbr;
	char	*str;

	str = "moves ";
	if (game->moves > 4)
	{
		game->link_moves++;
		ft_printf("moves = %d\n", game->link_moves);
		game->moves = 0;
	}
	retrieve_nbr = ft_itoa(game->link_moves);
	str = ft_strjoin(str, retrieve_nbr);
	free(retrieve_nbr);
	mlx_string_put(game->mlx, game->win, 13, 4, 255 * 256 * 256, str);
	free(str);
}

void	ft_print_stats(t_game *game)
{
	ft_print_img(game, game->stats_bg, 0, 0);
	if (game->get_exit == 1)
		ft_print_img(game, game->key, 235, 7);
	ft_print_moves(game);
	ft_rupee_collect(game);
}
