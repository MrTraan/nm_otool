/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_digit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 11:00:17 by ngrasset          #+#    #+#             */
/*   Updated: 2016/03/06 19:43:51 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		print_usize(t_format *f, va_list ap)
{
	size_t	c;
	char	*s;
	int		l;

	c = va_arg(ap, size_t);
	s = ft_uitoa_base((unsigned long long)c, 10);
	l = print_dstringf(f, s);
	free(s);
	return (l);
}

int		print_udigit(t_format *f, va_list ap)
{
	f->flags &= ~(F_SIGN | F_SPACE);
	if (f->modifier == 'l' || f->conv == 'U')
		return (print_ulong(f, ap));
	else if (f->modifier == 'H')
		return (print_usigned_char(f, ap));
	else if (f->modifier == 'h')
		return (print_ushort(f, ap));
	else if (f->modifier == 'L')
		return (print_ulong_long(f, ap));
	else if (f->modifier == 'j')
		return (print_uintmax(f, ap));
	else if (f->modifier == 'z')
		return (print_usize(f, ap));
	else
		return (print_uint(f, ap));
}
