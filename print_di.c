/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:37:56 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/14 11:39:34 by macrespo         ###   ########.fr       */
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

static int		print_width(t_flags flags, int size)
{
	char	zero;
	int		printed;

	zero = ' ';
	if (flags.zero == 1 && flags.dash == 0)
		zero = '0';
	while (size++ < flags.width)
	{
		write(1, &zero, 1);
		printed++;
	}
	return (printed);
}

int				print_di(va_list arg, t_flags flags)
{
	int		len;
	int		nb;
	int		printed;

	printed = 0;
	nb = va_arg(arg, int);
	len = len_num(nb);
	if (flags.dot == 1)
	{
		while (len < flags.precision)
		{
			write(1, "0", 1);
			printed++;
			len++;
		}
	}
	if (flags.width > 0 && flags.dash == 0)
		printed += print_width(flags, len);
	ft_putnbr_fd(nb, 1);
	if (flags.width > 0 && flags.dash == 1)
		printed += print_width(flags, len);
	if (flags.width > 0)
		return (printed);
	return (len);
}
