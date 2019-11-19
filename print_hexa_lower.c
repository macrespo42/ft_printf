/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:42:45 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/19 16:48:50 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_hexa_lower(unsigned int n)
{
	char			*hexa_base;

	hexa_base = "0123456789abcdef";
	if (n >= 16)
		print_hexa_lower(n / 16);
	write(1, &hexa_base[n % 16], 1);
}
