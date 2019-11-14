/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:26:03 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/14 15:44:48 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_put_hexa(unsigned long n)
{
	char *hexa_base;

	hexa_base = "0123456789abcdef";
	if (n >= 10)
		ft_put_hexa(n / 16);
	write(1, &hexa_base[n % 16], 1);
}

int		main(int ac, char **av)
{
	(void)ac;
	ft_put_hexa(4200000);
	return (0);
}
