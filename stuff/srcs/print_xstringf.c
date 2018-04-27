/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xstringf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 19:59:02 by ngrasset          #+#    #+#             */
/*   Updated: 2016/03/06 20:15:56 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	find_xstr_size(t_format *f, char *s)
{
	int		size;

	if (f->min_field_w - (F_ISALTER(f) ? 2 : 0) && !f->precision &&
			F_ISZERO(f) && !F_ISNEG(f))
		f->precision = f->min_field_w - (F_ISALTER(f) ? 2 : 0);
	size = (f->precision > (int)ft_strlen(s) ? f->precision : ft_strlen(s)) +
		(ft_isdigit(*s) && (F_ISSPACE(f) || F_ISSIGN(f)) ? 1 : 0) +
			(F_ISALTER(f) ? 2 : 0);
	return (size);
}

int			print_xstringf(t_format *f, char *s)
{
	int		l;
	int		size;

	l = 0;
	if (ft_strcmp(s, "0") == 0 && F_ISPRECIS(f) && f->precision == 0)
		return (0);
	size = find_xstr_size(f, s);
	if (!F_ISNEG(f))
		l += ft_putnchar(' ', f->min_field_w - size);
	if (F_ISSIGN(f) && ft_isdigit(*s))
		l += write(1, "+", 1);
	else if (F_ISSPACE(f) && ft_isdigit(*s))
		l += write(1, " ", 1);
	if (*s == '-')
	{
		l += write(1, "-", 1);
		s++;
	}
	l += write(1, "0x", (F_ISALTER(f) ? 2 : 0));
	l += ft_putnchar('0', f->precision - ft_strlen(s));
	l += write(1, s, ft_strlen(s));
	if (F_ISNEG(f))
		l += ft_putnchar(' ', f->min_field_w - l);
	return (l);
}
