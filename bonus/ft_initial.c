/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:35:56 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 17:47:43 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_initial2(t_game *game)
{
	game->y = 0;
	game->x = 0;
	game->i = 0;
	game->j = 0;
	game->moves = 0;
	game->link_moves = 0;
	game->frame = 0;
	game->get_exit = 0;
	game->i_fire = 0;
	game->i_ruby = 0;
	game->i_knight = 0;
	game->i_link_up = 0;
	game->i_link_dn = 0;
	game->i_link_rt = 0;
	game->i_link_lt = 0;
	game->i_blob = 0;
	game->start_game = 0;
	game->ending = 0;
	game->open_safe = 0;
	game->img_ht = 64;
	game->img_wh = 64;
}

void	ft_initial(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->x, game->y,
			"a Chris to the past");
	ft_initial2(game);
	game->link_keys[0] = '0';
	game->link_keys[1] = '0';
	game->link_keys[2] = '0';
	game->link_keys[3] = '0';
	game->blob_keys[0] = '0';
	game->blob_keys[1] = '0';
	game->blob_keys[2] = '0';
	game->blob_keys[3] = '0';
	game->sound_knight = 1;
	game->safe_x = 0;
	game->safe_y = 0;
	game->collectibles_nbr = 0;
	collectible_count(game);
	game->collected = 0;
}

void	*init_img(t_game *game, char *file)
{
	void	*ptr;

	ptr = mlx_xpm_file_to_image(game->mlx, file, &game->img_wh, &game->img_ht);
	if (!ptr)
	{
		ft_error(game, "init xpm failed !\n");
		ft_quit(game);
	}
	return (ptr);
}

void	ft_print_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}
