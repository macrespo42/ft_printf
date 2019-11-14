/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:26:03 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/14 16:04:45 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexa_lower(unsigned long n)
{
	char *hexa_base;

	hexa_base = "0123456789abcdef";
	if (n >= 10)
		ft_print_hexa_lower(n / 16);
	write(1, &hexa_base[n % 16], 1);
}
