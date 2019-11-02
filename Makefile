NAME = libftprintf.a

CC = clang -W

norm:
	norminette *.c *.h

.PHONY: norm
