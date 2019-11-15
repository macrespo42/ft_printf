/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:22:46 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/15 14:52:39 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_width(t_flags flags, int size)
{
	char	zero;
	int		printed;

	printed = 0;
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

static int		print_precision(t_flags flags, char *s)
{
	int		i;

	i = 0;
	if (flags.dot == 1 && (int)ft_strlen(s) > flags.precision)
	{
		while (i < flags.precision)
			i++;
	}
	else
	{
		if (s)
		{
			while (s[i])
			i++;
		}
	}
	write(1, s, i);
	return (i);
}

int				print_s(va_list arg, t_flags flags)
{
	char	*s;
	int		i;
	int		size_s;
	int		printed;

	printed = 0;
	i = 0;
	s = va_arg(arg, char*);
	if (s == NULL)
		s = "(null)";
	size_s = (int)ft_strlen(s);
	if (flags.dot == 1 && size_s > flags.precision)
	{
		if (flags.precision < size_s)
			size_s = flags.precision;
	}
	if (flags.width > 0 && flags.dash == 0)
		printed += print_width(flags, size_s);
	i += print_precision(flags, s);
	if (flags.dash == 1)
		printed += print_width(flags, size_s);
	return (i + printed);
}
