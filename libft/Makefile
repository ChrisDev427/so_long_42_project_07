# Makefile

NAME = libft.a
CC = gcc 
CFLAGS = -Wall -Wextra -Werror -I

SRCS = srcs/lst/ft_lstnew.c srcs/lst/ft_lstadd_front.c srcs/lst/ft_lstadd_back.c srcs/lst/ft_lstsize.c srcs/lst/ft_lstlast.c srcs/lst/ft_lstdelone.c srcs/lst/ft_lstclear.c srcs/lst/ft_lstiter.c srcs/lst/ft_lstmap.c \
	   srcs/lst/ft_lstprint_str.c srcs/lst/ft_lstadd_position.c srcs/lst/ft_lstdel_all.c srcs/lst/ft_lstdel_front.c srcs/lst/ft_lstdel_back.c srcs/lst/ft_lstdel_position.c srcs/lst/ft_lstprint_int.c \
	   srcs/str/ft_split.c srcs/str/ft_strjoin.c srcs/str/ft_strtrim.c srcs/str/ft_substr.c srcs/str/ft_striteri.c srcs/str/ft_strmapi.c srcs/str/ft_strnstr.c srcs/str/ft_strrchr.c srcs/str/ft_itoa.c srcs/str/ft_atoi.c srcs/str/ft_atoi_base.c \
	   srcs/str/ft_strchr.c srcs/str/ft_strtab_dup.c srcs/str/ft_found_char.c srcs/str/ft_strlcpy.c srcs/str/ft_strlcat.c srcs/str/ft_strncmp.c srcs/str/ft_strcmp.c srcs/str/ft_strdup.c srcs/str/ft_strlen.c srcs/str/ft_bzero.c srcs/str/ft_strrev.c srcs/str/ft_strcpy.c srcs/str/get_next_line.c \
	   srcs/to/ft_tolower.c srcs/to/ft_toupper.c \
	   srcs/print/ft_putendl_fd.c srcs/print/ft_putstr_fd.c srcs/print/ft_putchar_fd.c srcs/print/ft_putnbr_fd.c srcs/print/ft_putendl.c srcs/print/ft_putstr.c srcs/print/ft_putchar.c srcs/print/ft_putnbr.c \
	   srcs/print/ft_print_strs_array.c srcs/print/ft_putnbr_base.c \
	   srcs/mem/ft_calloc.c srcs/mem/ft_memchr.c srcs/mem/ft_memmove.c srcs/mem/ft_memcmp.c srcs/mem/ft_memset.c srcs/mem/ft_memcpy.c \
	   srcs/is/ft_isalpha.c srcs/is/ft_isprint.c srcs/is/ft_isalnum.c srcs/is/ft_isdigit.c srcs/is/ft_isascii.c \
	   srcs/tab/ft_nb_digit.c srcs/tab/ft_rev_int_tab.c srcs/tab/ft_sort_int_tab.c \
	   srcs/ft_printf/ft_putstr_ptf.c srcs/ft_printf/ft_printf.c srcs/ft_printf/ft_flag_linker.c srcs/ft_printf/ft_print_x.c srcs/ft_printf/ft_print_di.c srcs/ft_printf/ft_print_u.c srcs/ft_printf/ft_print_p.c \
	   srcs/free/free_str_tab.c srcs/free/free_int_tab2d.c

OBJECT_FILES = $(SRCS:.c=.o)

HEADER = ./

	
all: $(NAME)  
.c.o: 
	$(CC) $(CFLAGS) $(HEADER) -c  $< -o $(<:.c=.o)

$(NAME): $(OBJECT_FILES)
	@ar rsc $(NAME) $(OBJECT_FILES)
	@echo "$(GREEN)\n<<<<< libft.a created ! >>>>>$(DEFAULT)"

clean:
	@echo "$(RED)\n<<<<< deleting libft obj. files! >>>>>$(DEFAULT)"
	@rm -rf $(OBJECT_FILES)
	@echo "$(GREEN)\n<<<<< obj. files libft cleaned ! >>>>>$(DEFAULT)"

fclean: clean
	@echo "$(RED)\n<<<<< deleting libft.a >>>>>$(DEFAULT)"
	@rm -rf $(NAME)
	@echo "$(GREEN)\n<<<<< fclean libft done ! >>>>>$(DEFAULT)"

re: fclean all
	@echo "$(GREEN)<<<<< Make re libft done ! >>>>>$(DEFAULT)"

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m