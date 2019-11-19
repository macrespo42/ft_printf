/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:19:07 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/19 19:10:02 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				count_hexa(unsigned long n)
{
	int	printed;

	printed = 1;
	while (n >= 16)
	{
		n = n / 16;
		printed++;
	}
	return (printed + 2);
}

static int				print_precision(t_flags flags, unsigned long nb)
{
	int		len;
	int		printed;
	int		to_print;

	len = count_hexa(nb);
	to_print = flags.precision - len;
	printed = len < flags.precision ? flags.precision : len;
	if (flags.precision == 0 && nb == 0)
	{
		write(1, "0x", 2);
		return (2);
	}
	while (to_print-- > 0)
		write(1, "0", 1);
	print_address(nb);
	return (printed);
}

static int				print_width(t_flags flags, unsigned long nb)
{
	int		len;
	int		printed;
	int		to_print;
	char	width_char;

	width_char = ' ';
	if (flags.zero == 1 && flags.dash == 0)
		width_char = '0';
	len = count_hexa(nb);
	to_print = flags.width - len;
	printed = to_print + len;
	while (flags.dash == 0 && to_print-- > 0)
		write(1, &width_char, 1);
	write(1, "0x", 2);
	print_address(nb);
	while (flags.dash == 1 && to_print-- > 0)
		write(1, &width_char, 1);
	if (flags.width < len)
		return (len);
	return (printed);
}

static int				print_prewidth(t_flags flags, unsigned long nb, int len)
{
	int		printed;
	int		pre;
	int		wid;

	pre = flags.precision - len > 0 ? flags.precision - len : 0;
	wid = flags.width - (len + pre) > 0 ? flags.width - (len + pre) : 0;
	printed = pre + wid + len;
	if (flags.precision == 0 && nb == 0)
		wid += 1;
	while (flags.dash == 0 && wid-- > 0)
		write(1, " ", 1);
	if (flags.precision == 0 && nb == 0)
		write(1, "0x", 2);
	while (pre-- > 0)
		write(1, "0", 1);
	if (!(flags.precision == 0 && nb == 0))
		print_address(nb);
	while (flags.dash == 1 && wid-- > 0)
		write(1, " ", 1);
	return (printed);
}

int						print_memory(va_list arg, t_flags flags)
{
	unsigned long	nb;
	int				printed;

	printed = 0;
	nb = va_arg(arg, unsigned long);
	if (flags.width > 0 && flags.dot == 0)
		printed += print_width(flags, nb);
	else if (flags.width == 0 && flags.dot == 1)
		printed += print_precision(flags, nb);
	else if (flags.width > 0 && flags.dot == 1)
		printed += print_prewidth(flags, nb, count_hexa(nb));
	else
	{
		write(1, "0x", 2);
		print_address(nb);
		return (count_hexa(nb));
	}
	return (printed);
}
