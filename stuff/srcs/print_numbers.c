/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:05:15 by ngrasset          #+#    #+#             */
/*   Updated: 2016/03/06 19:43:06 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		print_size(t_format *f, va_list ap)
{
	size_t	c;
	char	*s;
	int		l;

	c = va_arg(ap, size_t);
	s = ft_itoa_base((long long)c, 10);
	l = print_dstringf(f, s);
	free(s);
	return (l);
}

int		print_digit(t_format *f, va_list ap)
{
	if (f->modifier == 'l' || f->conv == 'D')
		return (print_long(f, ap));
	else if (f->modifier == 'H')
		return (print_signed_char(f, ap));
	else if (f->modifier == 'h')
		return (print_short(f, ap));
	else if (f->modifier == 'L')
		return (print_long_long(f, ap));
	else if (f->modifier == 'j')
		return (print_intmax(f, ap));
	else if (f->modifier == 'z')
		return (print_size(f, ap));
	else
		return (print_int(f, ap));
}
