/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:19:07 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/19 13:59:37 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				count_hexa(unsigned long n)
{
	char			*hexa_base;
	static int		printed = 0;

	hexa_base = "0123456789abcdef";
	if (n >= 16)
		count_hexa(n / 16);
	printed += 1;
	return (printed);
}

int						print_memory(va_list arg, t_flags flags)
{
	unsigned long	nb;
	int				len;
	int				printed;

	(void)flags;
	printed = 0;
	nb = va_arg(arg, unsigned long);
	len = count_hexa(nb) + 2;
	write(1, "0x", 2);
	print_hexa_lower(nb);
	return (len + printed);
}
