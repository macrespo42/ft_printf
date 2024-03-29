/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:10:09 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/20 11:04:36 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			i_atoi(const char *str, int *pos, va_list args, t_flags *flags)
{
	int		res;

	res = 0;
	if (str[*pos] == '*')
	{
		res = va_arg(args, int);
		if (res < 0 && str[*pos - 1] == '.')
			flags->dot = 0;
		if (res < 0)
		{
			res = res * -1;
			flags->dash = 1;
		}
	}
	else
	{
		while (str[*pos] >= 48 && str[*pos] <= 57)
		{
			res = res * 10 + str[*pos] - '0';
			(*pos)++;
		}
		(*pos)--;
	}
	return (res);
}
