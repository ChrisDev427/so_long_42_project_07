/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:00:12 by chmassa           #+#    #+#             */
/*   Updated: 2023/03/09 10:56:08 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "mlx.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
//-----------------------------------------------------------------------------
//********* parsing struct ****************************************************
//-----------------------------------------------------------------------------
typedef struct s_game
{
	int		fd;
	char	**map;
	char	**mapcpy;
	char	*walls_elem;
	char	*obj_elem;
	int		get_exit;
	int		ending;
	int		sound_knight;
	int		sound_steps;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		i;
	int		j;
	int		start_game;
	int		blob_x;
	int		blob_y;
	int		link_x;
	int		link_y;
	int		collectibles_nbr;
	int		collected;
	int		img_wh;
	int		img_ht;
	char	link_keys[4];
	char	blob_keys[4];
	int		frame;
	int		moves;
	int		link_moves;
	void	*white_bg;
	void	*gold_bg;
	void	*title;
	void	*green_bg;
	void	*floor;
	void	*exit;
	void	*tp_rt;
	void	*tp_lt;
	void	*bt_rt;
	void	*bt_lt;
	void	*out_tp_rt;
	void	*out_tp_lt;
	void	*out_bt_rt;
	void	*out_bt_lt;
	void	*wall_n;
	void	*wall_s;
	void	*wall_e;
	void	*wall_w;
	void	*wall_brick;
	void	*roof;
	void	*safe_op;
	void	*safe_cl;
	void	*safe_key;
	void	*key;
	void	*win_img;
	void	*loose_img;
	void	*stats_bg;
	int		safe_y;
	int		safe_x;
	int		open_safe;
	int		i_ruby;
	void	*ruby[3];
	void	*jar;
	int		i_fire;
	void	*fire[4];
	int		i_link_up;
	int		i_link_dn;
	int		i_link_rt;
	int		i_link_lt;
	void	*link_fa[4];
	void	*link_bk[4];
	void	*link_rt[4];
	void	*link_lt[4];
	void	*pot;
	int		i_knight;
	int		i_blob;
	void	*blob[2];
	void	*knight[12];
	void	*shadow[12];
}				t_game;

enum e_map_init
{
	TOP_LT_IN_ANGL	= 'a',
	TOP_RT_IN_ANGL	= 'b',
	BT_LT_IN_ANGL	= 'c',
	BT_RT_IN_ANGL	= 'd',
	TOP_LT_OUT_ANGL = 'o',
	TOP_RT_OUT_ANGL = 'p',
	BT_LT_OUT_ANGL	= 'q',
	BT_RT_OUT_ANGL	= 'r',
	N_WALL			= 'n',
	S_WALL			= 's',
	W_WALL			= 'w',
	E_WALL			= 'e',
	I_WALL_SINGLE	= 'm',
	EMPTY_SPACE		= ' ',
	BRICK			= 'y',
	ROOF			= '/',
	safe_op			= '2',
	safe_cl			= '3',
	safe_key		= '4'
};
//-----------------------------------------------------------------------------
//******** parsing functions **************************************************
//-----------------------------------------------------------------------------
void	ft_open(char *file, int *fd);
void	ft_get_map(char *file, t_game *game);
void	ft_check_map_basics(t_game *game);
void	ft_check_valid_paths(t_game *game);
void	ft_error(t_game *game, char *s);
void	ft_window(t_game *game);
void	ft_initial(t_game *game);
//-----------------------------------------------------------------------------
//******** mapping ************************************************************
//-----------------------------------------------------------------------------
void	ft_map_transform(t_game *game);
void	map_initializer(t_game *game, int y, int x);
void	collectible_count(t_game *game);
//-----------------------------------------------------------------------------
//******** events functions ***************************************************
//-----------------------------------------------------------------------------
int		ft_quit(t_game *game);
void	items_sprites_init(t_game *game);
int		ft_keypress(int key, t_game *game);
int		ft_keyrelease(int key, t_game *game);
int		ft_run(t_game *game);
void	ft_print_fire(t_game *game);
void	link_sprites_init(t_game *game);
void	*init_img(t_game *game, char *file);
void	ft_print_img(t_game *game, void *img, int x, int y);
void	ft_print_map(t_game *game, char **s);
void	ft_print_roof(t_game *game);
void	ft_print_ruby(t_game *game);
void	ft_loose(t_game *game);
void	ft_win(t_game *game);
void	ft_title(t_game *game);
//****** players **************************************************************
void	ft_link(t_game *game);
void	ft_blob(t_game *game);
//****** players moves ********************************************************
void	ft_link_moves(t_game *game);
void	ft_walk_up(t_game *game);
void	ft_walk_down(t_game *game);
void	ft_walk_right(t_game *game);
void	ft_walk_left(t_game *game);
void	ft_blob_moves(t_game *game);
void	ft_print_stats(t_game *game);
//****** players animations ***************************************************
void	ft_print_knight(t_game *game);
void	ft_print_knight_shadow(t_game *game);
void	ft_link_anim(t_game *game, char c);
void	ft_blob_anim(t_game *game, char c);
//****** players positions ****************************************************
void	ft_players_positions(t_game *game);
void	so_long_bonus(t_game *game);
#endif