/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:01:07 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/14 17:22:42 by macrespo         ###   ########.fr       */
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

static unsigned int		print_width(t_flags flags, int size)
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

static void				ft_putunbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putunbr_fd(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
}

int						print_u(va_list arg, t_flags flags)
{
	unsigned int		len;
	unsigned int		nb;
	unsigned int		printed;

	printed = 0;
	nb = (unsigned int)va_arg(arg, int);
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
	ft_putunbr_fd(nb, 1);
	if (flags.width > 0 && flags.dash == 1)
		printed += print_width(flags, len);
	if (flags.width > 0)
		return (printed);
	return (len);
}
