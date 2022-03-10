override	NAME = libftprintf.a

override	SRCS = 	ft_printf.c\
					ft_print_str.c			ft_print_char.c			ft_number_bit.c\
					ft_print_pointer.c		ft_print_numeral.c		ft_print_decimal.c\
					ft_print_unsigned.c		ft_print_hex.c			ft_print_space.c\
					ft_print_percent.c\

LIB = libft.a
LIB_SRC = ../libft

override	OBJS = $(SRCS:%.c=%.o)
override	HEADER = ft_printf.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

.PHONY	: all clean fclean re

all		: $(LIB) $(NAME)

$(NAME)	: $(OBJS) $(HEADER) $(LIB_SRC)/$(LIB)
	ar rc $(NAME) $(OBJS) $(HEADER) $(LIB_SRC)/*.o

$(LIB)	:
	make all -C $(LIB_SRC)

%.o		: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(MAKE) clean -C $(LIB_SRC)
	rm -f $(OBJS)

fclean	: clean
	$(MAKE) fclean -C $(LIB_SRC)
	rm -f $(NAME)

re		: fclean all
