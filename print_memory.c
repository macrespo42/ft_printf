/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:19:07 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/15 15:29:54 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				count_hexa(unsigned long n)
{
	char			*hexa_base;
	static int		printed = 0;

	hexa_base = "0123456789abcdef";
	if (n >= 10)
		count_hexa(n / 16);
	printed += 1;
	return (printed);
}

static void				print_hexa_lower(unsigned long n)
{
	char			*hexa_base;

	hexa_base = "0123456789abcdef";
	if (n >= 10)
		print_hexa_lower(n / 16);
	write(1, &hexa_base[n % 16], 1);
}

static int				print_width(t_flags flags, int size, char zero)
{
	int		printed;

	printed = 0;
	while (size++ < flags.width)
	{
		write(1, &zero, 1);
		printed++;
	}
	return (printed);
}

int						print_memory(va_list arg, t_flags flags)
{
	unsigned long	nb;
	int				len;
	int				printed;

	printed = 0;
	nb = va_arg(arg, unsigned long);
	len = count_hexa(nb) + 2;
	if (flags.width > 0 && flags.dash == 0 && flags.zero == 0)
		printed += print_width(flags, len, ' ');
	write(1, "0x", 2);
	if (flags.width > 0 && flags.dash == 0 && flags.zero == 1)
		printed += print_width(flags, len, '0');
	if (flags.dot == 1 && nb == 0)
		len--;
	else
		print_hexa_lower(nb);
	if (flags.width > 0 && flags.dash == 1)
		printed += print_width(flags, len, ' ');
	return (len + printed);
}
