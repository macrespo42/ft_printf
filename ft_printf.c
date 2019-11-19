/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:12:05 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/19 12:06:38 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	active_flags(char *s, int pos, va_list args)
{
	t_flags flags;

	flags.zero = 0;
	flags.dot = 0;
	flags.width = 0;
	flags.dash = 0;
	while (s[pos] && !(is_convert_flag(s[pos])))
	{
		if (s[pos] == '0')
			flags.zero = 1;
		else if ((ft_isdigit(s[pos]) || s[pos] == '*'))
			flags.width = i_atoi(s, pos, args, &flags);
		else if (s[pos] == '-')
			flags.dash = 1;
		else if (s[pos] == '.')
		{
			flags.dot = 1;
			flags.precision = i_atoi(s, pos + 1, args, &flags);
			pos++;
		}
		while (ft_isdigit(s[pos + 1]) && s[pos] != '0' && s[pos] != '-')
			pos++;
		pos++;
	}
	return (flags);
}

static int		convert_flags(int *i, va_list args, char *s)
{
	int			printed;
	t_flags		flags;

	printed = 0;
	*i += 1;
	flags = active_flags(s, *i, args);
	while (!(is_convert_flag(s[*i])) && s[*i])
		*i += 1;
	if (s[*i] == 'c')
		printed += print_c(args, flags);
	if (s[*i] == 's')
		printed += print_s(args, flags);
	if (s[*i] == 'd' || s[*i] == 'i')
		printed += print_di(args, flags);
	if (s[*i] == 'u')
		printed += print_u(args, flags);
	if (s[*i] == 'x')
		printed += print_hexa(args, flags, 0);
	if (s[*i] == 'X')
		printed += print_hexa(args, flags, 1);
	if (s[*i] == 'p')
		printed += print_memory(args, flags);
	if (s[*i])
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
		if (s[i] == '%' && s[i + 1] != '%')
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
