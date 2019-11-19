/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:44:06 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/19 17:10:25 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_hexa_upper(unsigned int n)
{
	char			*hexa_base;

	hexa_base = "0123456789ABCDEF";
	if (n >= 16)
		print_hexa_upper(n / 16);
	write(1, &hexa_base[n % 16], 1);
}
