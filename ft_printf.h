/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 09:42:39 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/12 11:02:48 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# define BUFF_SIZE 4096

typedef struct		s_flags
{
	int				dash;
	int				width;
	int				precision;
	int				star;
}					t_flags;

int					ft_printf(const char *s, ...);
int					print_c(va_list arg);
int					print_s(va_list arg);
#endif
