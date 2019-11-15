/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:19:07 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/15 11:28:30 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int					print_hexa_lower(unsigned long n)
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

int						print_memory(va_list arg, t_flags flags)
{
	unsigned long	nb;
	int				len;
	int				printed;

	printed = 0;
	len = 2;
	write(1, "0x", 2);
	nb = va_arg(arg, unsigned long);
	printed += print_hexa_lower(nb);
	return (len + printed);
}
