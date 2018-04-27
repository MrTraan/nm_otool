/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 17:02:00 by ngrasset          #+#    #+#             */
/*   Updated: 2016/03/06 19:59:31 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			print_string(t_format *f, va_list ap)
{
	char	*s;
	wchar_t	*w;

	if (f->modifier == 'l' || f->conv == 'S')
	{
		w = va_arg(ap, wchar_t *);
		if (!w)
			return (print_stringf(f, "(null)"));
		return (print_string_wide(f, w));
	}
	else
	{
		s = va_arg(ap, char *);
		if (!s)
			s = "(null)";
		return (print_stringf(f, s));
	}
}

int			print_stringf(t_format *f, char *s)
{
	int		l;
	int		size;

	l = 0;
	size = (F_ISPRECIS(f) && f->precision < (int)ft_strlen(s) ?
		f->precision : ft_strlen(s));
	if (!(f->flags & F_NEG))
		l += ft_putnchar((f->flags & F_ZERO ? '0' : ' '),
				f->min_field_w - size);
	l += write(1, s, size);
	if (f->flags & F_NEG)
		l += ft_putnchar(' ', f->min_field_w - size);
	return (l);
}
