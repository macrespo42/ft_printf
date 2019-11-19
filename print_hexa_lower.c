/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:42:45 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/19 11:32:08 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_hexa_lower(unsigned long n)
{
	char			*hexa_base;
	static int		printed = 0;

	hexa_base = "0123456789abcdef";
	if (n >= 16)
		print_hexa_lower(n / 16);
	printed += 1;
	write(1, &hexa_base[n % 16], 1);
	return (printed);
}
