/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:01:07 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/20 11:14:45 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int		len_num(unsigned int n)
{
	unsigned int		len;

	len = 1;
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
	to_print = flags.precision - len;
	printed = len < flags.precision ? flags.precision + len - 1 : len;
	if (flags.precision == 0 && nb == 0)
		return (0);
	while (to_print-- > 0)
		write(1, "0", 1);
	putunbr(nb);
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
	if (flags.dash == 1)
		putunbr(nb);
	while (to_print-- > 0)
		write(1, &width_char, 1);
	if (flags.dash == 0)
		putunbr(nb);
	if (flags.width < len)
		return (len);
	return (printed);
}

static int				print_prewidth(t_flags flags, int nb, int len)
{
	int		printed;
	int		pre;
	int		wid;

	pre = flags.precision - len > 0 ? flags.precision - len : 0;
	wid = flags.width - (len + pre) > 0 ? flags.width - (len + pre) : 0;
	printed = pre + wid + len;
	if (flags.precision == 0 && nb == 0)
		wid += 1;
	if (flags.dash == 0)
	{
		while (wid-- > 0)
			write(1, " ", 1);
	}
	while (pre-- > 0)
		write(1, "0", 1);
	if (!(flags.precision == 0 && nb == 0))
		putunbr(nb);
	if (flags.dash == 1)
	{
		while (wid-- > 0)
			write(1, " ", 1);
	}
	return (printed);
}

int						print_u(va_list arg, t_flags flags)
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
		putunbr(nb);
		return (len_num(nb));
	}
	return (printed);
}
