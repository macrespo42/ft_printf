/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:37:56 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/19 18:04:12 by macrespo         ###   ########.fr       */
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

static int				print_precision(t_flags flags, int nb)
{
	int		len;
	int		printed;
	int		to_print;

	len = len_num(nb);
	to_print = nb > 0 ? flags.precision - len : flags.precision - (len - 1);
	printed = len < flags.precision ? flags.precision + len - 1: len;
	if (flags.precision == 0 && nb == 0)
		return (0);
	if (nb < 0)
		write(1, "-", 1);
	while (to_print-- > 0)
		write(1, "0", 1);
	if (!(nb == 0))
		putnbr(nb);
	return (printed);
}

static int				print_width(t_flags flags, int nb)
{
	int		len;
	int		printed;
	int		to_print;
	char	width_char;

	width_char = ' ';
	if (flags.zero == 1 && flags.dash == 0)
		width_char = '0';
	len = len_num(nb);
	to_print = flags.width - len;
	printed = to_print + len;
	if (nb < 0 && flags.zero == 1)
		write(1, "-", 1);
	while (flags.dash == 0 && to_print-- > 0)
		write(1, &width_char, 1);
	if (nb < 0 && flags.zero == 0)
		write(1, "-", 1);
	putnbr(nb);
	while (flags.dash == 1 && to_print-- > 0)
		write(1, &width_char, 1);
	if (flags.width < len)
		return (len);
	return (printed);
}

static int				print_prewidth(t_flags flags, int nb, int len)
{
	int		printed;
	int		pre;
	int		wid;

	pre = nb > 0 ? flags.precision - len : flags.precision - (len - 1);
	pre = flags.precision - len > 0 ? pre : 0;
	wid = flags.width - (len + pre) > 0 ? flags.width - (len + pre) : 0;
	printed = pre + wid + len;
	if (nb == 0)
		wid += 1;
	while (flags.dash == 0 && wid-- > 0)
		write(1, " ", 1);
	if (nb < 0)
		write(1, "-", 1);
	while (pre-- > 0)
		write(1, "0", 1);
	if (!(nb == 0))
		putnbr(nb);
	while (flags.dash == 1 && wid-- > 0)
		write(1, " ", 1);
	return (printed);
}

int				print_di(va_list arg, t_flags flags)
{
	int		nb;
	int		printed;

	printed = 0;
	nb = va_arg(arg, int);
	if (flags.width > 0 && flags.dot == 0)
		printed += print_width(flags, nb);
	else if (flags.width == 0 && flags.dot == 1)
		printed += print_precision(flags, nb);
	else if (flags.width > 0 && flags.dot == 1)
		printed += print_prewidth(flags, nb, len_num(nb));
	else
	{
		if (nb < 0)
			write(1, "-", 1);
		putnbr(nb);
		return (len_num(nb));
	}
	return (printed);
}
