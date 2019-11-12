/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:10:09 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/12 18:16:25 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			i_atoi(const char *str, int pos, t_flags *flags)
{
	int		res;
	int		i;

	i = 0;
	res = 0;
	while (str[pos] >= 48 && str[pos] <= 57)
	{
		res = res * 10 + str[pos] - '0';
		pos++;
		i++;
	}
	flags->width = res;
	return (i);
}
