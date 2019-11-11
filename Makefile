NAME = libftprintf.a

CC = clang -W

all: $(NAME)

norm:
	norminette *.c *.h

.PHONY: norm
