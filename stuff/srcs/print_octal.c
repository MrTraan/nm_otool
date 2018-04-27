/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:14:54 by ngrasset          #+#    #+#             */
/*   Updated: 2016/03/06 19:42:50 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		print_octal_size(t_format *f, va_list ap)
{
	size_t	c;
	char	*s;
	int		l;

	c = va_arg(ap, size_t);
	s = ft_uitoa_base((unsigned long long)c, 8);
	if (f->precision < (int)ft_strlen(s) && F_ISALTER(f))
	{
		f->flags |= F_PRECIS;
		f->precision = (int)ft_strlen(s) + 1;
		if (c == 0)
			f->precision--;
	}
	l = print_dstringf(f, s);
	free(s);
	return (l);
}

int		print_octal_digit(t_format *f, va_list ap)
{
	f->flags &= ~(F_SIGN | F_SPACE);
	if (f->modifier == 'l' || f->conv == 'O')
		return (print_octal_long(f, ap));
	else if (f->modifier == 'H')
		return (print_octal_char(f, ap));
	else if (f->modifier == 'h')
		return (print_octal_short(f, ap));
	else if (f->modifier == 'L')
		return (print_octal_long_long(f, ap));
	else if (f->modifier == 'j')
		return (print_octal_intmax(f, ap));
	else if (f->modifier == 'z')
		return (print_octal_size(f, ap));
	else
		return (print_octal_int(f, ap));
}
