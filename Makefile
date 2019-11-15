NAME = libftprintf.a

CC = clang -W

all:
	gcc *.c libft/*.c -c -I ./
	ar rcs $(NAME) *.o
norm:
	norminette *.c *.h

.PHONY: norm

re: all
