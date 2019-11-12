/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:14:32 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/12 18:51:41 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_c(va_list arg, t_flags flags)
{
	char	c;
	char	zero;
	int		i;

	zero = ' ';
	if (flags.zero == 1)
		zero = '0';
	i = 0;
	if (flags.width > 0 || flags.dash > 0)
	{
		while (i++ < (flags.width - 1))
			write(1, &zero, 1);
		i--;
	}
	c = va_arg(arg, int);
	write(1, &c, 1);
	return (1 + i);
}
