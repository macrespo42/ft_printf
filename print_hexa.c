/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:42:45 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/19 14:00:12 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						print_hexa(va_list arg, t_flags flags, int upper)
{
	unsigned long	nb;
	int				len;
	int				printed;

	printed = 0;
	len = 0;
	(void)flags;
	nb = va_arg(arg, unsigned long);
	if (upper == 0)
		printed += print_hexa_lower(nb);
	else
		printed += print_hexa_upper(nb);
	return (len + printed);
}
