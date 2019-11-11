/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:12:05 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/11 18:14:01 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void		clear_buffer(char *buffer, int printed)
{
	int		i;

	write(1, buffer, printed);
	i = 0;
	while (i < printed)
	{
		buffer[i] = '\0';
		i++;
	}
}

static int		which_convert(char *s, int *pos)
{
	/*atm this version do not support flags */
	*pos += 1;
	if (s[*pos] == 'c')
		return (0);
	else if (s[*pos] == 's')
		return (1);
	else
		return (-1);
}

int				ft_printf(const char *s, ...)
{
	char		buffer[BUFF_SIZE];
	va_list		args;
	int			printed;
	int			i;
	// void		(*convert_flags[6](void));

	// fill_tab()
	printed = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			which_convert((char*)s, &i);
			i += 1;
			print_c(buffer, &printed, args);
		}
		else
			buffer[printed++] = s[i++];
	}
	va_end(args);
	buffer[i] = '\0';
	if (buffer[0] != '\0')
		clear_buffer(buffer, printed);
	return (printed);
}
