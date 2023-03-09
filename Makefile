# Makefile


NAME = so_long
NAME_BONUS = so_long_bonus
LIBFT = libft/
CC = gcc 
CFLAGS = -Wall -Wextra -Werror
MLX_PATH = -L/usr/local/lib -lmlx
OPENGL = -framework OpenGL
APPKIT = -framework AppKit
SRCS =  srcs/so_long.c \
		srcs/ft_quit.c \
		srcs/ft_initial.c \
		srcs/parsing/ft_get_map.c \
		srcs/parsing/ft_check_map_basics.c \
		srcs/parsing/ft_check_valid_paths.c \
		srcs/parsing/ft_open.c \
		srcs/ft_error.c \
		srcs/ft_window.c \
		srcs/ft_init_sprites.c \
		srcs/ft_print_map.c \
		srcs/link_position.c \
		srcs/parsing/collectibles_count.c \
		srcs/ft_keymap.c
SRCS_BONUS =  bonus/so_long_bonus.c \
			  bonus/parsing/ft_get_map.c \
			  bonus/parsing/ft_open.c \
			  bonus/parsing/ft_check_map_basics.c \
			  bonus/parsing/ft_check_valid_paths.c \
			  bonus/ft_initial.c \
			  bonus/ft_error.c \
			  bonus/map_transform/ft_map_transform.c \
			  bonus/map_transform/map_initializer.c \
			  bonus/ft_window.c \
			  bonus/ft_title.c \
			  bonus/items_sprites_init.c \
			  bonus/link_sprites_init.c \
			  bonus/ft_players_positions.c \
			  bonus/ft_print_roof.c \
			  bonus/ft_print_map.c \
			  bonus/ft_print_stats.c \
			  bonus/ft_print_fire.c \
			  bonus/ft_players.c \
			  bonus/ft_link_moves.c \
			  bonus/ft_link_anim.c \
			  bonus/ft_blob_moves.c \
			  bonus/ft_blob_anim.c \
			  bonus/ft_knight.c \
			  bonus/ft_walk_up.c \
			  bonus/ft_walk_down.c \
			  bonus/ft_walk_right.c \
			  bonus/ft_walk_left.c \
			  bonus/ft_key.c \
			  bonus/ft_run.c \
			  bonus/parsing/collectibles_count.c \
			  bonus/ft_quit.c

OBJECT_FILES = $(SRCS:.c=.o)
OBJECT_BONUS = $(SRCS_BONUS:.c=.o)

HEADER = -I./includes

all: $(NAME) 
.c.o:
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

$(NAME): $(OBJECT_FILES)
	@echo "$(YELLOW)\n<<<<< libft compiling ... >>>>>\n$(DEFAULT)"
	$(MAKE) -C $(LIBFT)
	cp ./libft/libft.a $(NAME)
	@echo "$(YELLOW)\n<<<<< Creating $(NAME) exec file ! ... >>>>>$(DEFAULT)"
	$(CC) $(CFLAGS) $(HEADER) -o $(NAME) $(SRCS) $(MLX_PATH) $(OPENGL) $(APPKIT) libft/libft.a 
	@echo "$(GREEN)\n<<<<< $(NAME) created ! ... >>>>>\n$(DEFAULT)"
#------------------------------------------------------------------------------
clean: 
	@echo "$(RED)\n<<<<< deleting $(NAME) obj. files ! ... >>>>>$(DEFAULT)"
	rm -rf $(OBJECT_FILES) $(OBJECT_BONUS)
	@echo "$(GREEN)<<<<< clean from $(NAME) done ! >>>>>\n$(DEFAULT)"
	$(MAKE) clean -C $(LIBFT)
#------------------------------------------------------------------------------
fclean: clean
	@echo "$(RED)<<<<< deleting $(NAME) exec ! >>>>>\n$(DEFAULT)"
	rm -rf $(NAME) $(NAME_BONUS)
	$(MAKE) fclean -C $(LIBFT)
	@echo "$(GREEN)<<<<< fclean from $(NAME) done ! >>>>>\n$(DEFAULT)"
#------------------------------------------------------------------------------
re: fclean all
	@echo "$(GREEN)\n<<<<< $(NAME) make re done ! >>>>>\n$(DEFAULT)"
#------------------------------------------------------------------------------
bonus: $(NAME_BONUS) $(OBJECT_BONUS)

$(NAME_BONUS): $(OBJECT_BONUS)
	$(MAKE) -C $(LIBFT)
	cp ./libft/libft.a $(NAME_BONUS)
	@echo "$(YELLOW)\n<<<<< Creating pipex_bonus exec file ! ... >>>>>\n$(DEFAULT)"
	$(CC) $(CFLAGS) $(HEADER) -o $(NAME_BONUS) $(SRCS_BONUS) $(MLX_PATH) $(OPENGL) $(APPKIT) libft/libft.a
	@echo "$(GREEN)\n<<<<< $(NAME_BONUS) created ! ... >>>>>\n$(DEFAULT)"



#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
#------------------------------------------------------------------------------
#DEBUG
# -fsanitize=address
# valgrind --leak-check=full
