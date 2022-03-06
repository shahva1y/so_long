NAME = so_long
NAME_BONUS = bonus

SRCS =	main.c\
		ft_parse_file.c\
		ft_read_file.c\
		ft_get_next_line.c\
		ft_parse_map.c\
		\
		ft_check_utils.c\
		\
		ft_key_press.c\
		ft_frame_update.c\
		\
		ft_t_mlx_utils.c\
		ft_t_meta_utils.c\
		ft_t_img_utils.c\
		ft_t_set_utils.c\
		ft_t_list_utils.c\
		ft_t_hero_utils.c\
		ft_t_map_utils.c\
		\
		ft_free.c\
		ft_exit.c\

LIB = libft.a
LIB_SRC = ./libft

LIB_PRINT = libftprintf.a
LIB_PRINT_SRC = ./ft_printf

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)
HEADER = so_long.h
HEADER_BONUS = so_long.h

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

fclean	: clean
	$(MAKE) fclean -C $(LIB_SRC)
	$(MAKE) fclean -C $(LIB_PRINT_SRC)
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

bonus	:
	rm -f $(OBJS)
	make SRCS='$(SRCS_BONUS)' HEADER='$(HEADER_BONUS)' all

re		: fclean all