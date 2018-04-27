/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dstringf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 19:57:22 by ngrasset          #+#    #+#             */
/*   Updated: 2016/03/06 20:14:54 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	find_dstr_size(t_format *f, char *s)
{
	int		size;
	int		my_p;

	my_p = f->precision + (*s == '-' ? 1 : 0);
	if (f->precision || F_ISNEG(f))
		f->flags &= ~(F_ZERO);
	if (*s == '-')
		f->flags &= ~(F_SIGN | F_SPACE);
	size = S_MAX((int)ft_strlen(s), (F_ISZERO(f) ? S_MAX(my_p,
			f->min_field_w - M_SIGN(f, s)) : my_p)) + M_SIGN(f, s);
	return (size);
}

int			print_dstringf(t_format *f, char *s)
{
	int		l;
	int		size;

	l = 0;
	if (ft_strcmp(s, "0") == 0 && F_ISPRECIS(f) && f->precision == 0)
		return (0);
	size = find_dstr_size(f, s);
	if (!F_ISNEG(f) && !F_ISZERO(f))
		l += ft_putnchar(' ', f->min_field_w - size);
	if (F_ISSIGN(f) && ft_isdigit(*s))
		l += write(1, "+", 1);
	else if (F_ISSPACE(f) && ft_isdigit(*s))
		l += write(1, " ", 1);
	if (*s == '-')
	{
		l += write(1, s++, 1);
		if (F_ISZERO(f))
			f->min_field_w--;
	}
	l += ft_putnchar('0', (F_ISZERO(f) ? f->min_field_w - M_SIGN(f, s) :
			f->precision) - ft_strlen(s));
	l += write(1, s, ft_strlen(s));
	if (F_ISNEG(f) && !F_ISZERO(f))
		l += ft_putnchar(' ', f->min_field_w - size);
	return (l);
}
