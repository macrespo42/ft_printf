/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:12:05 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/12 12:42:34 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		convert_flags(int *i, va_list args, char *s)
{
	/* *i += 1; is in wait to support flags */
	int		printed;

	printed = 0;
	*i += 1;
	if (s[*i] == 'c')
		printed += print_c(args);
	if (s[*i] == 's')
		printed += print_s(args);
	*i += 1;
	return (printed);
}


int				ft_printf(const char *s, ...)
{
	va_list		args;
	int			printed;
	int			i;

	printed = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
			printed += convert_flags(&i, args, (char*)s);
		else
		{
			write(1, &s[i], 1);
			printed++;
			i++;
		}
	}
	va_end(args);
	return (printed);
}
