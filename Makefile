NAME = so_long
NAME_BONUS = bonus

SRCS =	main.c\
		ft_process_args.c\
		ft_parse_file.c\
		ft_list_utils.c\
		ft_parse_map.c\

LIB = libft.a
LIB_SRC = ./libft

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)
HEADER = so_long.h
HEADER_BONUS = so_long.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

.PHONY	: all clean fclean re bonus

all		: $(LIB) $(NAME)

$(NAME): $(OBJS) $(LIB_SRC)/$(LIB)
	$(CC) $(OBJS) $(LIB_SRC)/$(LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIB)	:
	make all -C $(LIB_SRC)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean	:
	$(MAKE) clean -C $(LIB_SRC)
	rm -f $(OBJS)

fclean	: clean
	$(MAKE) fclean -C $(LIB_SRC)
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

bonus	:
	rm -f $(OBJS)
	make SRCS='$(SRCS_BONUS)' HEADER='$(HEADER_BONUS)' all

re		: fclean all