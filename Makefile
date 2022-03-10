NAME = so_long
NAME_BONUS = so_long_bonus

SRCS =	src/main.c\
		src/ft_parse_file.c\
		src/ft_read_file.c\
		src/ft_get_next_line.c\
		src/ft_parse_map.c\
		\
		src/ft_check_utils.c\
		\
		src/ft_key_press.c\
		src/ft_frame_update.c\
		\
		src/ft_t_mlx_utils.c\
		src/ft_t_meta_utils.c\
		src/ft_t_img_utils.c\
		src/ft_t_set_utils.c\
		src/ft_t_list_utils.c\
		src/ft_t_hero_utils.c\
		src/ft_t_map_utils.c\
		\
		src/ft_free.c\
		src/ft_exit.c\

SRCS_BONUS =	bonus/main_bonus.c\
                bonus/ft_parse_file_bonus.c\
                bonus/ft_read_file_bonus.c\
                bonus/ft_get_next_line_bonus.c\
                bonus/ft_parse_map_bonus.c\
                \
                bonus/ft_check_utils_bonus.c\
                \
                bonus/ft_key_press_bonus.c\
                bonus/ft_frame_update_bonus.c\
                \
                bonus/ft_t_mlx_utils_bonus.c\
                bonus/ft_t_meta_utils_bonus.c\
                bonus/ft_t_img_utils_bonus.c\
                bonus/ft_t_set_utils_bonus.c\
                bonus/ft_t_list_utils_bonus.c\
                bonus/ft_t_hero_utils_bonus.c\
                bonus/ft_t_enemy_utils_bonus.c\
                bonus/ft_t_map_utils_bonus.c\
                \
            	bonus/ft_t_cell_utils_bonus.c\
            	bonus/ft_t_cell_init_utils_bonus.c\
                bonus/ft_free_bonus.c\
                bonus/ft_exit_bonus.c\

LIB = libft.a
LIB_SRC = ./libft

LIB_PRINT = libftprintf.a
LIB_PRINT_SRC = ./ft_printf

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)
HEADER = src/so_long.h
HEADER_BONUS = bonus/so_long_bonus.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

.PHONY	: all clean fclean re bonus

all		: $(LIB) $(LIB_PRINT) $(NAME)

$(NAME): $(OBJS) $(LIB_SRC)/$(LIB) $(LIB_PRINT_SRC)/$(LIB_PRINT)
	$(CC) $(OBJS) $(LIB_SRC)/$(LIB) $(LIB_PRINT_SRC)/$(LIB_PRINT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIB)	:
	make all -C $(LIB_SRC)

$(LIB_PRINT)	:
	make all -C $(LIB_PRINT_SRC)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean	:
	$(MAKE) clean -C $(LIB_SRC)
	$(MAKE) clean -C $(LIB_PRINT_SRC)
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean	: clean
	$(MAKE) fclean -C $(LIB_SRC)
	$(MAKE) fclean -C $(LIB_PRINT_SRC)
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

bonus	:
	rm -f $(OBJS)
	make SRCS='$(SRCS_BONUS)' HEADER='$(HEADER_BONUS)' NAME='$(NAME_BONUS)' all

re		: fclean all