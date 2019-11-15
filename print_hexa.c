/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:42:45 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/15 11:54:51 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				print_hexa_lower(unsigned long n)
{
	char			*hexa_base;
	static int		printed = 0;

	hexa_base = "0123456789abcdef";
	if (n >= 10)
		print_hexa_lower(n / 16);
	printed += 1;
	write(1, &hexa_base[n % 16], 1);
	return (printed);
}

static int				print_hexa_upper(unsigned long n)
{
	char			*hexa_base;
	static int		printed = 0;

	hexa_base = "0123456789ABCDEF";
	if (n >= 10)
		print_hexa_upper(n / 16);
	printed += 1;
	write(1, &hexa_base[n % 16], 1);
	return (printed);
}

int						print_hexa(va_list arg, t_flags flags, int upper)
{
	unsigned long	nb;
	int				len;
	int				printed;

	printed = 0;
	len = 0;
	nb = va_arg(arg, unsigned long);
	if (upper == 0)
		printed += print_hexa_lower(nb);
	else
		printed += print_hexa_upper(nb);
	return (len + printed);
}
