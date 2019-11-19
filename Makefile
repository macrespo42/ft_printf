NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

SRC = ft_printf.c \
	ft_isdigit.c \
	ft_strlen.c \
	i_atoi.c \
	is_convert_flag.c \
	print_c.c \
	print_di.c \
	print_s.c \
	print_u.c \
	print_hexa_lower.c \
	print_hexa_upper.c \
	print_hexa.c \
	putunbr.c \
	putnbr.c \
	print_memory.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	$(CC) main.c -L. libftprintf.a && ./a.out

norm:
	norminette $(SRC) $(HEADER)

.PHONY: all re clean fclean test norm
