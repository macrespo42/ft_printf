/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:44:06 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/19 11:29:01 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_hexa_upper(unsigned long n)
{
	char			*hexa_base;
	static int		printed = 0;

	hexa_base = "0123456789ABCDEF";
	if (n >= 16)
		print_hexa_upper(n / 16);
	printed += 1;
		write(1, &hexa_base[n % 16], 1);
	return (printed);
}
