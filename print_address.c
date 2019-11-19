/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:22:15 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/19 18:39:45 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_address(unsigned long n)
{
	char			*hexa_base;

	hexa_base = "0123456789abcdef";
	if (n >= 16)
		print_address(n / 16);
	write(1, &hexa_base[n % 16], 1);
}
