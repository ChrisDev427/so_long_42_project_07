/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:54:19 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/08 18:56:21 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	so_long_bonus(t_game *game)
{
	ft_check_valid_paths(game);
	ft_check_map_basics(game);
	ft_window(game);
	ft_map_transform(game);
	ft_initial(game);
	link_sprites_init(game);
	items_sprites_init(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		ft_get_map(argv[1], &game);
		so_long_bonus(&game);
		ft_players_positions(&game);
		ft_title(&game);
		mlx_hook(game.win, 2, 0, ft_keypress, &game);
		mlx_hook(game.win, 3, 0, ft_keyrelease, &game);
		mlx_hook(game.win, 17, 0, ft_quit, &game);
		mlx_loop_hook(game.mlx, ft_run, &game);
		mlx_loop(game.mlx);
	}
	else
		ft_error(&game, "Invalid arguments number\n");
	return (0);
}
