/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:37:56 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/18 16:26:37 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		len_num(int n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		len++;
		if (n == -2147483648)
			return (11);
		else
			n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int		precision_size(t_flags flags, int size)
{
	int		to_print;

	to_print = 0;
	if (flags.dot == 1)
	{
		while (size < flags.precision)
		{
			size++;
			to_print++;
		}
	}
	return (to_print);
}

static int		print_width(t_flags flags, int size)
{
	char	zero;
	int		printed;

	zero = ' ';
	printed = 0;
	if (flags.zero == 1 && flags.dash == 0)
		zero = '0';
	while (size++ < flags.width)
	{
		write(1, &zero, 1);
		printed++;
	}
	return (printed);
}

static int		print_flags(t_flags flags, int size)
{
	int		printed;
	int		to_print;

	printed = 0;
	to_print = precision_size(flags, size);
	size += to_print;
	if (flags.dash == 0)
		printed += print_width(flags, size);
	while (to_print-- > 0)
	{
		write(1, "0", 1);
		printed++;
	}
	if (flags.dash == 1)
		printed += print_width(flags, size);
	return (printed);
}

int				print_di(va_list arg, t_flags flags)
{
	int		len;
	int		nb;
	int		printed;

	nb = va_arg(arg, int);
	len = len_num(nb);
	printed = len;
	if ((flags.width > 0 && flags.dash == 0) || flags.dot == 1)
		printed += print_flags(flags, len);
	putnbr(nb);
	if (flags.width > 0 && flags.dash == 1)
		printed += print_flags(flags, printed);
	if (flags.width > 0 || flags.dot == 1)
		return (printed);
	return (len);
}
