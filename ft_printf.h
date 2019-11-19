/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 09:42:39 by macrespo          #+#    #+#             */
/*   Updated: 2019/11/19 11:46:56 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_flags
{
	int				zero;
	int				dash;
	int				width;
	int				dot;
	int				precision;
}					t_flags;

int					ft_printf(const char *s, ...);
int					i_atoi(const char *str, int pos, va_list args,
	t_flags *flags);
int					is_convert_flag(char c);
int					print_c(va_list arg, t_flags flags);
int					print_s(va_list arg, t_flags flags);
int					print_di(va_list arg, t_flags flags);
int					print_u(va_list arg, t_flags flags);
int					print_hexa(va_list arg, t_flags flags, int upper);
int					print_hexa_lower(unsigned long n);
int					print_hexa_upper(unsigned long n);
int					print_memory(va_list arg, t_flags flags);
void				putnbr(long n);
void				putunbr(unsigned int n);
#endif
