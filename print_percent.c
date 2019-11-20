/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:44:28 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/20 10:45:09 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		width_flags(t_flags flags, char c)
{
	int		i;

	i = 0;
	while (i++ < (flags.width - 1))
		write(1, &c, 1);
	return (i - 1);
}

int				print_percent(t_flags flags)
{
	char	zero;
	int		i;

	zero = ' ';
	if (flags.zero == 1 && flags.dash == 0)
		zero = '0';
	i = 0;
	if (flags.width > 0 && flags.dash == 0)
		i += width_flags(flags, zero);
	write(1, "%", 1);
	if (flags.dash > 0)
		i += width_flags(flags, zero);
	return (1 + i);
}
