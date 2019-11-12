/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:12:05 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/12 18:56:34 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	active_flags(char *s, int pos)
{
	t_flags flags;

	flags.zero = 0;
	flags.dot = 0;
	flags.width = 0;
	flags.dash = 0;
	while (s[pos] && (s[pos] != 'c'))
	{
		if (s[pos] == '0')
			flags.zero = 1;
		else if (ft_isdigit(s[pos]))
			pos += i_atoi(s, pos, &flags, 1);
		else if (s[pos] == '-')
			pos += i_atoi(s, pos, &flags, 2);
		// else if (s[pos] == '.')
		// {
		// 	flags.dot = 1;
		// 	flags.precision = i_atoi(s, pos, &flags, 3);
		// }
		pos++;
	}
	return (flags);
}

static int		convert_flags(int *i, va_list args, char *s)
{
	/* *i += 1; is in wait to support flags */
	int		printed;
	t_flags flags;

	printed = 0;
	*i += 1;
	flags = active_flags(s, *i);
	while (!(is_convert_flag(s[*i])))
		*i += 1;
	if (s[*i] == 'c')
		printed += print_c(args, flags);
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
