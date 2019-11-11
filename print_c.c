/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:14:32 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/11 18:14:48 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_c(char *buffer, int *pos, va_list arg)
{
	char c;

	c = va_arg(arg, int);
	buffer[*pos] = (char)c;
	*pos += 1;
}
