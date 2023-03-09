/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:49:24 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/09 14:32:53 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_game *game)
{
	ft_check_map_basics(game);
	ft_check_valid_paths(game);
	game->parse.mapcpy = ft_strtab_dup(game->parse.map);
	ft_window(game);
	ft_initial(game);
	ft_init_sprites(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		ft_get_map(argv[1], &game);
		so_long(&game);
		link_position(&game);
		mlx_key_hook(game.win.win_ptr, ft_keymap, &game);
		ft_print_map(&game);
		mlx_hook(game.win.win_ptr, 17, 0, ft_quit, &game);
		mlx_loop(game.win.mlx_ptr);
	}
	else
		ft_error(&game, "Invalid arguments number\n");
	return (0);
}
